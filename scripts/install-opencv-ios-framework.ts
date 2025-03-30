import fs from "fs";
import path from "path";
import {fileURLToPath} from "url";
import downloadReleases from "@etclabscore/dl-github-releases";
import extract from "extract-zip";
import {rimraf} from "rimraf";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
//console.log(__filename);
//console.log(__dirname);`

const user = "opencv";
const repo = "opencv";
const outputdir = path.join(__dirname, "../.tmp"); // Download to repository root

let selectedRelease: any = undefined;
let selectedAsset: any = undefined;

// Define a function to filter assets.
function filterAsset(asset: any) {
    return selectedAsset === asset;
}

// Define a function to filter releases.
function filterRelease(release: any) {
    if (selectedRelease && selectedAsset || release.prerelease === true) {
        return false;
    }
    console.log("Downloading release: ", release.name);
    selectedRelease = release;
    selectedAsset = release.assets.find((asset: any) => {
        const isZip = asset.content_type.indexOf("application/zip") >= 0;
        const isIosFramework = asset.name.indexOf("ios-framework") >= 0;
        return isZip && isIosFramework;
    });
    if (selectedAsset) {
        console.log("Downloading asset: ", selectedAsset.name);
    }
    return true;
}

async function run() {
    try {
        const result = await downloadReleases(user, repo, outputdir, filterRelease as any, filterAsset as any, false);
        console.log(result);
        if (selectedRelease) {
            try {
                await extract(path.join(outputdir, selectedRelease.tag_name, selectedAsset.name), {
                    dir: path.join(__dirname, ".."),
                });
                console.log("OpenCV iOS framework extracted");
            } catch (err) {
                console.log(err);
            }
            if (fs.existsSync(outputdir)) {
                console.log("Cleaning up");
                rimraf.sync(outputdir, {});
            }
        }
    } catch (error) {
        console.error(error);
    }
    process.exit();
}

run();
