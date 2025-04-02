import { type HybridObject } from 'react-native-nitro-modules';
export interface Scalar {
    readonly a: number;
    readonly b: number;
    readonly c: number;
    readonly d: number;
}
export interface CvScalar extends HybridObject<{
    ios: "c++";
    android: "c++";
}>, Scalar {
    toJsValue(): Scalar;
}
