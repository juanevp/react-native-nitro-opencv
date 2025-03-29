import {NitroModules} from "react-native-nitro-modules";

import type {DataTypes} from "./specs/data-types";
import type {ColorConversion} from "./specs/functions-color-conversion.nitro";
import type {Core} from "./specs/functions-core.nitro";
import type {ImageTransform} from "./specs/functions-image-transform.nitro";
import type {Misc} from "./specs/functions-misc.nitro";
import type {ObjectDetection} from "./specs/functions-object-detection.nitro";
import type {Shape} from "./specs/functions-shape.nitro";
import type {MatVector} from "./specs/mat-vector.nitro";
import type {CvMat} from "./specs/mat.nitro";
import type {Objects} from "./specs/objects.nitro";
import type {Point2fVector, PointVector, PointVectorOfVectors} from "./specs/point-vector.nitro";
import type {CvPoint, CvPoint2f} from "./specs/point.nitro";
import type {RectVector} from "./specs/rect-vector.nitro";
import type {CvRect} from "./specs/rect.nitro";
import type {CvScalar} from "./specs/scalar.nitro";
import type {CvSize} from "./specs/size.nitro";
import type { ImageFiltering } from "./specs/functions-image-filtering.nitro";
import type { Feature } from "./specs/functions-feature.nitro";
import type { Drawing } from "./specs/functions-drawing.nitro";

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

const core = NitroModules.createHybridObject<Core>("Core");
const objects_ = NitroModules.createHybridObject<Objects>("Objects");
const colorConversion = NitroModules.createHybridObject<ColorConversion>("ColorConversion");
const shape = NitroModules.createHybridObject<Shape>("Shape");
const objectDetection = NitroModules.createHybridObject<ObjectDetection>("ObjectDetection");
const misc = NitroModules.createHybridObject<Misc>("Misc");
const imageTransform = NitroModules.createHybridObject<ImageTransform>("ImageTransform");
const imageFiltering = NitroModules.createHybridObject<ImageFiltering>("ImageFiltering");
const feature = NitroModules.createHybridObject<Feature>("Feature");
const drawing = NitroModules.createHybridObject<Drawing>("Drawing");

function createMat(rows: number, cols: number, dataType: DataTypes, data?: number[]): CvMat {
    return objects_.createMat(rows, cols, dataType, data);
}

function createMatVector(): MatVector {
    return objects_.createMatVector();
}

function createPoint(x: number, y: number): CvPoint {
    return objects_.createPoint(x, y);
}

function createPointVector(): PointVector {
    return objects_.createPointVector();
}

function createPointVectorOfVectors(): PointVectorOfVectors {
    return objects_.createPointVectorOfVectors();
}

function createPoint2f(x: number, y: number): CvPoint2f {
    return objects_.createPoint2f(x, y);
}

function createPoint2fVector(): Point2fVector {
    return objects_.createPoint2fVector();
}

function createRect(x: number, y: number, width: number, height: number): CvRect {
    return objects_.createRect(x, y, width, height);
}

function createRectVector(): RectVector {
    return objects_.createRectVector();
}

function createSize(width: number, height: number): CvSize {
    return objects_.createSize(width, height);
}

function createScalar(): CvScalar;
function createScalar(a: number): CvScalar;
function createScalar(a: number, b: number, c: number): CvScalar;
function createScalar(a: number, b: number, c: number, d: number): CvScalar;
function createScalar(a?: number, b?: number, c?: number, d?: number): CvScalar {
    return objects_.createScalar(a, b, c, d);
}

function base64ToMat(data: string): CvMat {
    return objects_.base64ToMat(data);
}

export type BufferType = {
    uint8: Uint8Array;
    uint16: Uint16Array;
    uint32: Uint32Array;
    int8: Int8Array;
    int16: Int16Array;
    int32: Int32Array;
    float32: Float32Array;
    float64: Float64Array;
};

export type ImportBufferType = Omit<BufferType, "uint32">;
//type BufferItemType = keyof BufferType;
type ImportBufferItemType = keyof ImportBufferType;

function bufferToMat(
    rows: number,
    cols: number,
    channels: 1 | 3 | 4,
    input: ImportBufferType[ImportBufferItemType]
): CvMat {
    const buffer = input.buffer;
    if (buffer instanceof SharedArrayBuffer) {
        throw new Error("SharedArrayBuffer not supported");
    }
    let itemType: ImportBufferItemType;
    if (input instanceof Uint8Array) {
        itemType = "uint8";
    } else if (input instanceof Uint16Array) {
        itemType = "uint16";
    } else if (input instanceof Int8Array) {
        itemType = "int8";
    } else if (input instanceof Int16Array) {
        itemType = "int16";
    } else if (input instanceof Int32Array) {
        itemType = "int32";
    } else if (input instanceof Float32Array) {
        itemType = "float32";
    } else if (input instanceof Float64Array) {
        itemType = "float64";
    } else {
        throw new Error(`Unsupported buffer type`);
    }
    return objects_.arrayBufferToMat(itemType, rows, cols, channels, buffer);
}

function matToBuffer<T extends keyof BufferType>(
    mat: CvMat,
    type: T
): {
    cols: number;
    rows: number;
    channels: number;
    buffer: BufferType[T];
} {
    const result = objects_.matToArrayBuffer(mat);
    if (type === "uint8") {
        return new Uint8Array(result) as any;
    } else if (type === "uint16") {
        return new Uint16Array(result) as any;
    } else if (type === "uint32") {
        return new Uint32Array(result) as any;
    } else if (type === "int8") {
        return new Int8Array(result) as any;
    } else if (type === "int16") {
        return new Int16Array(result) as any;
    } else if (type === "int32") {
        return new Int32Array(result) as any;
    } else if (type === "float32") {
        return new Float32Array(result) as any;
    } else if (type === "float64") {
        return new Float64Array(result) as any;
    }
    throw new Error(`Unsupported buffer type`);
}

const objects = {
    createMat,
    createMatVector,
    createPoint,
    createPointVector,
    createPointVectorOfVectors,
    createPoint2f,
    createPoint2fVector,
    createRect,
    createRectVector,
    createSize,
    createScalar,
    bufferToMat,
    base64ToMat,
    matToBuffer,
};

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
} as const;
