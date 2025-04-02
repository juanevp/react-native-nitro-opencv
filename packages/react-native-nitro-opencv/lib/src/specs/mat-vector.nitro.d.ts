import { type HybridObject } from "react-native-nitro-modules";
import type { CvMat } from "./mat.nitro";
import type { Size } from "./size.nitro";
export interface MatInfo {
    readonly cols: number;
    readonly rows: number;
    readonly size: Size;
}
export interface MatVector extends HybridObject<{
    ios: "c++";
    android: "c++";
}> {
    toJsValue(): MatInfo[];
    copyAt(index: number): CvMat;
}
