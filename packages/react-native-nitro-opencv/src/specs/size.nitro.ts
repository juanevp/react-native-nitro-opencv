import type { HybridObject } from "react-native-nitro-modules";

export interface Size {
    readonly width: number;
    readonly height: number;
}

export interface CvSize extends HybridObject<{ios: "c++", android: "c++"}>, Size {
    toJsValue(): Size;
}

