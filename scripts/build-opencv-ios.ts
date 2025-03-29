import fs from "node:fs";
import path from "node:path";
import {$} from "bun";

const excluded_modules = [
    "calib3d",
    "dnn",
    //"flann",
    "gapi",
    "highgui",
    "java",
    "js",
    "ml",
    "objc",
    "objdetect",
    "python",
    //"stitching",
    "ts",
    "video",
    "world",
    "dpm",
    "face",
    "fuzzy",
    "hdf",
    "line_descriptor",
    "matlab",
    "plot",
    "reg",
    "rgbd",
    "saliency",
    "sfm",
    "stereo",
    "text",
    "xphoto",
    "surface_matching",
    "photo",
    "cudaarithm",
    "cudabgsegm",
    "cudacodec",
    "viz",
    "cudastereo",
    "datasets",
    "cudafeatures2d",
    "cudafilters",
    "cudaimgproc",
    "cudalegacy",
    "cudaobjdetect",
    "cudaoptflow",
    "cudawarping",
    "cudev",
    "shape",
    "superres",
    "videostab",
    "ccalib",
    "structured_light",
    "tracking",
    "aruco",
    "bgsegm",
    "cvv",
]

const buildOutputRelPath = "opencv-builds/ios";

if (!fs.existsSync(buildOutputRelPath)) {
    fs.mkdirSync(buildOutputRelPath, {recursive: true});
}

const originalDir = (await $`pwd`.text()).split("\n")[0];
console.log(`originalDir: ${originalDir}`);

const buildDir = path.join(originalDir!, buildOutputRelPath);
console.log(`buildDir: ${buildDir}`);
//await $`rm -rf ${buildDir}`;

try {
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
    const exclusions = excluded_modules.map(s => `--without ${s}`).join(" ");
    // Add "--contrib ${opencvContribRepoPath}/modules" to include opencv_contrib
    await $`python3 "${opencvRepoPath}/platforms/ios/build_framework.py" --out ${buildDir} --iphoneos_archs=arm64 -iphonesimulator_archs=arm64,x86_64 --iphoneos_deployment_target=13 --disable-bitcode --disable-swift --build_only_specified_archs ${exclusions}`
        
} finally {
    await $.cwd(originalDir);
}
