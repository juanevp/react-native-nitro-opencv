import { type HybridObject } from "react-native-nitro-modules";
import type { CvRect, Rect } from "./rect.nitro";
export interface RectVector extends HybridObject<{
    ios: "c++";
    android: "c++";
}> {
    toJsValue(): Rect[];
    copyAt(index: number): CvRect;
}
