import type { HybridObject } from "react-native-nitro-modules";

export interface Rect {
    readonly x: number;
    readonly y: number;
    readonly width: number;
    readonly height: number;
}

export interface CvRect extends HybridObject<{ios: "c++", android: "c++"}>, Rect {
    toJsValue(): Rect;
}

