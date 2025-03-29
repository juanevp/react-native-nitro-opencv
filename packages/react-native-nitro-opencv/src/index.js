"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __exportStar = (this && this.__exportStar) || function(m, exports) {
    for (var p in m) if (p !== "default" && !Object.prototype.hasOwnProperty.call(exports, p)) __createBinding(exports, m, p);
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.OpenCV = void 0;
var react_native_nitro_modules_1 = require("react-native-nitro-modules");
__exportStar(require("./specs/constants-color-conversions-codes"), exports);
__exportStar(require("./specs/constants-core"), exports);
__exportStar(require("./specs/constants-image-processing"), exports);
__exportStar(require("./specs/data-types"), exports);
__exportStar(require("./specs/functions-color-conversion.nitro"), exports);
__exportStar(require("./specs/functions-core.nitro"), exports);
__exportStar(require("./specs/functions-drawing.nitro"), exports);
__exportStar(require("./specs/functions-feature.nitro"), exports);
__exportStar(require("./specs/functions-image-filtering.nitro"), exports);
__exportStar(require("./specs/functions-image-transform.nitro"), exports);
__exportStar(require("./specs/functions-misc.nitro"), exports);
__exportStar(require("./specs/functions-object-detection.nitro"), exports);
__exportStar(require("./specs/functions-shape.nitro"), exports);
__exportStar(require("./specs/mat-vector.nitro"), exports);
__exportStar(require("./specs/mat.nitro"), exports);
__exportStar(require("./specs/objects.nitro"), exports);
__exportStar(require("./specs/point-vector.nitro"), exports);
__exportStar(require("./specs/point.nitro"), exports);
__exportStar(require("./specs/rect-vector.nitro"), exports);
__exportStar(require("./specs/rotated-rect.nitro"), exports);
__exportStar(require("./specs/rect.nitro"), exports);
__exportStar(require("./specs/scalar.nitro"), exports);
__exportStar(require("./specs/size.nitro"), exports);
var core = react_native_nitro_modules_1.NitroModules.createHybridObject("Core");
var objects_ = react_native_nitro_modules_1.NitroModules.createHybridObject("Objects");
var colorConversion = react_native_nitro_modules_1.NitroModules.createHybridObject("ColorConversion");
var shape = react_native_nitro_modules_1.NitroModules.createHybridObject("Shape");
var objectDetection = react_native_nitro_modules_1.NitroModules.createHybridObject("ObjectDetection");
var misc = react_native_nitro_modules_1.NitroModules.createHybridObject("Misc");
var imageTransform = react_native_nitro_modules_1.NitroModules.createHybridObject("ImageTransform");
var imageFiltering = react_native_nitro_modules_1.NitroModules.createHybridObject("ImageFiltering");
var feature = react_native_nitro_modules_1.NitroModules.createHybridObject("Feature");
var drawing = react_native_nitro_modules_1.NitroModules.createHybridObject("Drawing");
function createMat(rows, cols, dataType, data) {
    return objects_.createMat(rows, cols, dataType, data);
}
function createMatVector() {
    return objects_.createMatVector();
}
function createPoint(x, y) {
    return objects_.createPoint(x, y);
}
function createPointVector() {
    return objects_.createPointVector();
}
function createPointVectorOfVectors() {
    return objects_.createPointVectorOfVectors();
}
function createPoint2f(x, y) {
    return objects_.createPoint2f(x, y);
}
function createPoint2fVector() {
    return objects_.createPoint2fVector();
}
function createRect(x, y, width, height) {
    return objects_.createRect(x, y, width, height);
}
function createRectVector() {
    return objects_.createRectVector();
}
function createSize(width, height) {
    return objects_.createSize(width, height);
}
function createScalar(a, b, c, d) {
    return objects_.createScalar(a, b, c, d);
}
function base64ToMat(data) {
    return objects_.base64ToMat(data);
}
function bufferToMat(rows, cols, channels, input) {
    var buffer = input.buffer;
    if (buffer instanceof SharedArrayBuffer) {
        throw new Error("SharedArrayBuffer not supported");
    }
    var itemType;
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
        throw new Error("Unsupported buffer type");
    }
    return objects_.arrayBufferToMat(itemType, rows, cols, channels, buffer);
}
function matToBuffer(mat, type) {
    var result = objects_.matToArrayBuffer(mat);
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
    throw new Error("Unsupported buffer type");
}
var objects = {
    createMat: createMat,
    createMatVector: createMatVector,
    createPoint: createPoint,
    createPointVector: createPointVector,
    createPointVectorOfVectors: createPointVectorOfVectors,
    createPoint2f: createPoint2f,
    createPoint2fVector: createPoint2fVector,
    createRect: createRect,
    createRectVector: createRectVector,
    createSize: createSize,
    createScalar: createScalar,
    bufferToMat: bufferToMat,
    base64ToMat: base64ToMat,
    matToBuffer: matToBuffer,
};
exports.OpenCV = {
    core: core,
    objects: objects,
    colorConversion: colorConversion,
    shape: shape,
    objectDetection: objectDetection,
    misc: misc,
    imageTransform: imageTransform,
    imageFiltering: imageFiltering,
    feature: feature,
    drawing: drawing,
};
