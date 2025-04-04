import type { HybridObject } from "react-native-nitro-modules";
export interface Range {
    readonly start: number;
    readonly end: number;
}
export interface CvRange extends HybridObject<{
    ios: "c++";
    android: "c++";
}>, Range {
    empty(): boolean;
    size(): number;
    toJsValue(): Range;
}
