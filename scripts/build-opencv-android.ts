import fs from "node:fs";
import path from "node:path";
import os from "os";
import {$} from "bun";

const buildOutputRelPath = "opencv-builds/android";

if (!fs.existsSync(buildOutputRelPath)) {
    fs.mkdirSync(buildOutputRelPath, {recursive: true});
}

const originalDir = (await $`pwd`.text()).split("\n")[0];
console.log(`originalDir: ${originalDir}`);

const buildDir = path.join(originalDir!, buildOutputRelPath);
console.log(`buildDir: ${buildDir}`);
//await $`rm -rf ${buildDir}`;

try {
    const androidHomePath = process.env.ANDROID_HOME ?? process.env.ANDROID_SDK ?? process.env.ANDROID_SDK_ROOT;
    if (!androidHomePath) {
        console.error("One of the environment variables ANDROID_HOME/ANDROID_SDK/ANDROID_SDK_ROOT must be defined");
        process.exit();
    }
    console.info(`Android SDK: ${androidHomePath}`);
    const ndkHome = await getNdkHome(androidHomePath);
    console.info(`Android NDK: ${ndkHome}`);
    let openCl = "";
    if (process.env.ENABLE_OPENCL) {
        openCl = "--opencl";
    }
    const opencvRepoPath = `submodules/OpenCV`;
    if (!fs.existsSync(opencvRepoPath)) {
        console.error(`OpenCV repository not found at ${opencvRepoPath}.`);
        process.exit();
    }
    const opencvContribRepoPath = `submodules/OpenCV_contrib`;
    if (!fs.existsSync(opencvContribRepoPath)) {
        console.error(`OpenCV_contrib repository not found at ${opencvContribRepoPath}.`);
        process.exit();
    }
    const cmakePath = await getCMakePath(androidHomePath);
    if (cmakePath) {
        const newPath = `${path.join(cmakePath, "bin")};${process.env.Path}`;
        $.env({...process.env, Path: newPath});
    }

    // Add "--extra_modules_path ${opencvContribRepoPath}/modules" to include opencv_contrib
    await $`python3 "${opencvRepoPath}/platforms/android/build_sdk.py" ${buildDir} ${opencvRepoPath} --config "${originalDir}/scripts/android.config.py" --sdk_path "${androidHomePath}" --ndk_path "${ndkHome}" --no_kotlin ${openCl} --no_samples_build`

    if (os.platform() === "win32") {
        fixBuild_java_shared_aar(`${opencvRepoPath}/platforms/android/build_java_shared_aar.py`);
    }
    $.cwd(buildDir);
    await $`python3 "${originalDir}/${opencvRepoPath}/platforms/android/build_java_shared_aar.py" ${buildDir}/OpenCV-android-sdk --ndk_location "${ndkHome.replaceAll("\\", "\\\\")}" --cmake_location "${cmakePath?.replaceAll("\\", "\\\\")}"`;
} finally {
    $.cwd(originalDir);
}

function getNdkHome(androidHomePath: string) {
    let ndkHome = process.env.ANDROID_NDK_HOME ?? process.env.ANDROID_NDK ?? process.env.NDKROOT;
    if (!ndkHome) {
        const ndkRoot = path.join(androidHomePath, "ndk");
        if (!fs.existsSync(ndkRoot)) {
            console.error("No NDK found.");
            process.exit();
        }
        //Choose latest ndk available
        ndkHome = fs.readdirSync(ndkRoot).sort().reverse()[0];
        if (!ndkHome) {
            console.error("No NDK found.");
            process.exit();
        }
        console.warn(
            "No NDK root variable defined (ANDROID_NDK_HOME/ANDROID_NDK/NDKROOT). Defaulting to ndk " + ndkHome
        );
        ndkHome = path.join(ndkRoot, ndkHome);
    }
    return ndkHome;
}

function getCMakePath(androidHomePath: string) {
    const cmakeRoot = path.join(androidHomePath, "cmake");
    if (!fs.existsSync(cmakeRoot)) {
        return undefined;
    }
    //Choose latest ndk available
    const cmakeHome = fs.readdirSync(cmakeRoot).sort().reverse()[0];
    if (!cmakeHome) {
        return undefined;
    }
    console.warn("Using cmake " + cmakeHome);
    return path.join(cmakeRoot, cmakeHome);
}

function fixBuild_java_shared_aar(path: string) {
    // In Windows, gradlew is a bat file. It means that the shell is required to execute it and the command name cannot start with "./"
    const orig = fs.readFileSync(path, {
        encoding: "utf-8"
    });
    const newBody = orig.replaceAll(`cmd = ["./gradlew",`, `cmd = ["gradlew",`).replaceAll("shell=False", "shell=True");
    fs.writeFileSync(path, newBody, {
        encoding: "utf-8"
    });
}
