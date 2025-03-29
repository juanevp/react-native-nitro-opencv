import {type HybridObject} from "react-native-nitro-modules";

import type {CvPoint, CvPoint2f, Point} from "./point.nitro";

export interface PointVector extends HybridObject<{ios: "c++"; android: "c++"}> {
    toJsValue(): Point[];
    copyAt(index: number): CvPoint;
}

export interface Point2fVector extends HybridObject<{ios: "c++"; android: "c++"}> {
    toJsValue(): Point[];
    copyAt(index: number): CvPoint2f;
}

export interface PointVectorOfVectors extends HybridObject<{ios: "c++"; android: "c++"}> {
    toJsValue(): Point[][];
    copyAt(index: number): PointVector;
}
