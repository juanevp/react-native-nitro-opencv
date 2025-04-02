import { type HybridObject } from 'react-native-nitro-modules';
import type { CvSize, Size } from './size.nitro';
export interface Mat {
    readonly cols: number;
    readonly rows: number;
    readonly size: Size;
    readonly base64: string;
}
export type MatImageFormat = "jpeg" | "png";
export interface CvMat extends HybridObject<{
    ios: "c++";
    android: "c++";
}>, Mat {
    readonly depth: number;
    readonly channels: number;
    readonly empty: boolean;
    readonly size: CvSize;
    toBase64(format?: MatImageFormat): string;
    toJsValue(format?: MatImageFormat): Mat;
}
