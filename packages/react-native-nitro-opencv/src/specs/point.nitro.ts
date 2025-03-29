import type { HybridObject } from "react-native-nitro-modules";

export interface Point {
    readonly x: number;
    readonly y: number;
}


export interface CvPoint extends HybridObject<{ios: "c++", android: "c++"}>, Point {
    toJsValue(): Point;
}

export interface CvPoint2f extends HybridObject<{ios: "c++", android: "c++"}>, Point {
    toJsValue(): Point;
}
