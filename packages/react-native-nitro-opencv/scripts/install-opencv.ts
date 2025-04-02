import "dotenv/config";

import fs from "fs";
import os from "os";
import path, {join} from "path";
import {fileURLToPath} from "url";
import downloadReleases from "@etclabscore/dl-github-releases";
import extract from "extract-zip";
import {rimraf} from "rimraf";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
//console.log(__filename);
//console.log(__dirname);`

if (!process.env.OPENCV_GITHUB_RELEASE) {
    throw new Error("Environment variable OPENCV_GITHUB_RELEASE not defined");
}
const releaseName = process.env.OPENCV_GITHUB_RELEASE;

const user = "opencv";
const repo = "opencv";
const tmpdir = path.join(__dirname, "../.tmp");
const installdir = path.join(__dirname, "../opencv");

let selectedRelease: any = undefined;
let selectedAssets: any[] = [];

// Define a function to filter assets.
function filterAsset(asset: any) {
    return selectedAssets.includes(asset);
}

const assetFilters = ["android"];
if (os.platform() === "darwin") {
    assetFilters.push("ios");
}

// Define a function to filter releases.
function filterRelease(release: any) {
    if (release.name !== releaseName) {
        return false;
    }
    console.log("Downloading release: ", release.name);
    selectedRelease = release;
    selectedAssets.push(
        ...release.assets.filter((asset: any) => {
            const isZip = asset.content_type.indexOf("application/zip") >= 0;
            const isIosFramework = assetFilters.some(s => asset.name.indexOf(s) >= 0);
            return isZip && isIosFramework;
        })
    );
    if (selectedAssets.length > 0) {
        console.log(
            "Downloading assets: ",
            selectedAssets.map(s => s.name),
            join(", ")
        );
    }
    return true;
}

async function run() {
    const releaseNameFile = path.join(installdir, "release-name");
    if (fs.existsSync(releaseNameFile)) {
        const installedRelease = fs.readFileSync(releaseNameFile).toString().trim();
        if (installedRelease === releaseName) {
            console.log(`OpenCV release '${releaseName}' already installed`);
            process.exit(0);
        } else {
            console.log("Deleting old OpenCV installation");
            rimraf.sync(installdir, {});
        }
    }
    console.log("Installing OpenCV release");
    try {
        const result = await downloadReleases(user, repo, tmpdir, filterRelease as any, filterAsset as any, false);
        console.log(`Found assets: ${result.join(", ")}`);
        if (selectedRelease) {
            for (const selectedAsset of selectedAssets) {
                try {
                    await extract(path.join(tmpdir, selectedRelease.tag_name, selectedAsset.name), {
                        dir: installdir,
                    });
                    console.log(`OpenCV release ${selectedAsset.name} installed`);
                } catch (err) {
                    console.log(err instanceof Error ? err.message : err);
                }
            }
            if (fs.existsSync(installdir)) {
                fs.writeFileSync(releaseNameFile, releaseName);
            }
            if (fs.existsSync(tmpdir)) {
                console.log("Cleaning up");
                rimraf.sync(tmpdir, {});
            }
        } else {
            console.error(`OpenCV release "${releaseName}" not found`);
        }
    } catch (error) {
        console.error(error);
    }
    process.exit();
}

run();
