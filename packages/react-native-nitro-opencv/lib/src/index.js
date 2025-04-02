import { NitroModules } from "react-native-nitro-modules";
export * from "./specs/constants-color-conversions-codes";
export * from "./specs/constants-core";
export * from "./specs/constants-image-processing";
export * from "./specs/data-types";
export * from "./specs/functions-color-conversion.nitro";
export * from "./specs/functions-core.nitro";
export * from "./specs/functions-drawing.nitro";
export * from "./specs/functions-feature.nitro";
export * from "./specs/functions-image-filtering.nitro";
export * from "./specs/functions-image-transform.nitro";
export * from "./specs/functions-misc.nitro";
export * from "./specs/functions-object-detection.nitro";
export * from "./specs/functions-shape.nitro";
export * from "./specs/mat-vector.nitro";
export * from "./specs/mat.nitro";
export * from "./specs/objects.nitro";
export * from "./specs/point-vector.nitro";
export * from "./specs/point.nitro";
export * from "./specs/rect-vector.nitro";
export * from "./specs/rotated-rect.nitro";
export * from "./specs/rect.nitro";
export * from "./specs/scalar.nitro";
export * from "./specs/size.nitro";
const core = NitroModules.createHybridObject("Core");
const objects = NitroModules.createHybridObject("Objects");
const colorConversion = NitroModules.createHybridObject("ColorConversion");
const shape = NitroModules.createHybridObject("Shape");
const objectDetection = NitroModules.createHybridObject("ObjectDetection");
const misc = NitroModules.createHybridObject("Misc");
const imageTransform = NitroModules.createHybridObject("ImageTransform");
const imageFiltering = NitroModules.createHybridObject("ImageFiltering");
const feature = NitroModules.createHybridObject("Feature");
const drawing = NitroModules.createHybridObject("Drawing");
const boxedCore = NitroModules.box(core);
const boxedObjects = NitroModules.box(objects);
const boxedColorConversion = NitroModules.box(colorConversion);
const boxedShape = NitroModules.box(shape);
const boxedObjectDetection = NitroModules.box(objectDetection);
const boxedMisc = NitroModules.box(misc);
const boxedImageTransform = NitroModules.box(imageTransform);
const boxedImageFiltering = NitroModules.box(imageFiltering);
const boxedFeature = NitroModules.box(feature);
const boxedDrawing = NitroModules.box(drawing);
export const OpenCV = {
    core,
    objects,
    colorConversion,
    shape,
    objectDetection,
    misc,
    imageTransform,
    imageFiltering,
    feature,
    drawing,
};
export const boxedOpenCV = {
    unbox() {
        "worklet";
        return {
            core: boxedCore.unbox(),
            objects: boxedObjects.unbox(),
            colorConversion: boxedColorConversion.unbox(),
            shape: boxedShape.unbox(),
            objectDetection: boxedObjectDetection.unbox(),
            misc: boxedMisc.unbox(),
            imageTransform: boxedImageTransform.unbox(),
            imageFiltering: boxedImageFiltering.unbox(),
            feature: boxedFeature.unbox(),
            drawing: boxedDrawing.unbox(),
        };
    },
};
export function bufferToMat(openCV, rows, cols, channels, input) {
    "worklet";
    const buffer = input.buffer;
    if (!(buffer instanceof ArrayBuffer)) {
        throw new Error("SharedArrayBuffer not supported");
    }
    let itemType;
    if (input instanceof Uint8Array) {
        itemType = "uint8";
    }
    else if (input instanceof Uint16Array) {
        itemType = "uint16";
    }
    else if (input instanceof Int8Array) {
        itemType = "int8";
    }
    else if (input instanceof Int16Array) {
        itemType = "int16";
    }
    else if (input instanceof Int32Array) {
        itemType = "int32";
    }
    else if (input instanceof Float32Array) {
        itemType = "float32";
    }
    else if (input instanceof Float64Array) {
        itemType = "float64";
    }
    else {
        throw new Error(`Unsupported buffer type`);
    }
    return openCV.objects.arrayBufferToMat(itemType, rows, cols, channels, buffer);
}
export function matToBuffer(openCV, mat, type) {
    "worklet";
    const result = openCV.objects.matToArrayBuffer(mat);
    if (type === "uint8") {
        return new Uint8Array(result);
    }
    else if (type === "uint16") {
        return new Uint16Array(result);
    }
    else if (type === "uint32") {
        return new Uint32Array(result);
    }
    else if (type === "int8") {
        return new Int8Array(result);
    }
    else if (type === "int16") {
        return new Int16Array(result);
    }
    else if (type === "int32") {
        return new Int32Array(result);
    }
    else if (type === "float32") {
        return new Float32Array(result);
    }
    else if (type === "float64") {
        return new Float64Array(result);
    }
    throw new Error(`Unsupported buffer type`);
}
