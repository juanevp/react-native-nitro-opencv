import type { HybridObject } from "react-native-nitro-modules";
export interface RotatedRect {
    readonly centerX: number;
    readonly centerY: number;
    readonly width: number;
    readonly height: number;
    readonly angle: number;
}
export interface CvRotatedRect extends HybridObject<{
    ios: "c++";
    android: "c++";
}>, RotatedRect {
    toJsValue(): RotatedRect;
}
