import {type HybridObject} from "react-native-nitro-modules";

import type {DataTypes} from "./data-types";
import type {MatVector} from "./mat-vector.nitro";
import type {CvMat} from "./mat.nitro";
import type {Point2fVector, PointVector, PointVectorOfVectors} from "./point-vector.nitro";
import type {CvPoint, CvPoint2f} from "./point.nitro";
import type {CvRange} from "./range.nitro";
import type {RectVector} from "./rect-vector.nitro";
import type {CvRect} from "./rect.nitro";
import type {CvRotatedRect} from "./rotated-rect.nitro";
import type {CvScalar} from "./scalar.nitro";
import type {CvSize} from "./size.nitro";

export type BufferItemType = "uint8" | "uint16" | "uint32" | "int8" | "int16" | "int32" | "float32" | "float64";
export type ImportBufferItemType = "uint8" | "uint16" | "int8" | "int16" | "int32" | "float32" | "float64";
//Omit<BufferItemType, "uint32">;

export interface Objects extends HybridObject<{ios: "c++"; android: "c++"}> {
    createMat(rows: number, cols: number, dataType: DataTypes, data?: number[]): CvMat;
    createMatVector(): MatVector;
    createPoint(x: number, y: number): CvPoint;
    createPointVector(): PointVector;
    createPointVectorOfVectors(): PointVectorOfVectors;
    createPoint2f(x: number, y: number): CvPoint2f;
    createPoint2fVector(): Point2fVector;
    createRange(start: number, end: number): CvRange;
    createRangeAll(): CvRange;
    createRect(x: number, y: number, width: number, height: number): CvRect;
    createRectVector(): RectVector;
    createRotatedRect(centerX: number, centerY: number, width: number, height: number, angle: number): CvRotatedRect;
    createSize(width: number, height: number): CvSize;
    createScalar(a?: number, b?: number, c?: number, d?: number): CvScalar;
    /**
     * Converts a byte array to a Mat.
     * @param rows - the number of rows in the Mat
     * @param cols - the number of columns in the Mat
     * @param channels - the number of channels in the Mat
     * @param input - the byte array to convert
     */
    arrayBufferToMat(
        itemType: ImportBufferItemType,
        rows: number,
        cols: number,
        channels: 1 | 3 | 4,
        input: ArrayBuffer
    ): CvMat;
    /**
     * Converts a base64 string to a Mat.
     * @param data - the base64 string to convert
     */
    base64ToMat(data: string): CvMat;
    /**
     * Converts a Mat to a byte array.
     * @param mat - the Mat to convert
     * @param type - the type of the buffer to return ('uint8' or 'float32')
     */
    matToArrayBuffer(mat: CvMat): ArrayBuffer;
}
