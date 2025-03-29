import {type HybridObject} from "react-native-nitro-modules";

import type {BorderTypes, DecompTypes} from "./constants-core";
import type {InterpolationFlags} from "./constants-image-transform";
import type {CvMat} from "./mat.nitro";
import type {PointVector} from "./point-vector.nitro";
import type {CvScalar} from "./scalar.nitro";
import type {CvSize} from "./size.nitro";

export interface ImageTransform extends HybridObject<{ios: "c++"; android: "c++"}> {
    /**
     * Calculates a perspective transform from four pairs of the corresponding points.
     * @param name Function name.
     * @param src Coordinates of quadrangle vertices in the source image.
     * @param dst Coordinates of the corresponding quadrangle vertices in the destination image.
     * @param solveMethod method passed to cv::solve (DecompTypes)
     */
    getPerspectiveTransform(src: PointVector, dst: PointVector, solveMethod: DecompTypes): CvMat;

    /**
     * Applies an affine transformation to an image.
     * @param name Function name.
     * @param src input image.
     * @param dst output image that has the size dsize and the same type as src
     * @param M transformation matrix
     * @param dsize size of the output image
     */
    warpAffine(src: CvMat, dst: CvMat, M: CvMat, dsize: CvSize): void;

    /**
     * Applies a perspective transformation to an image.
     * @param name Function name.
     * @param src input image.
     * @param dst output image that has the size dsize and the same type as src .
     * @param M 3x3 transformation matrix
     * @param size size of the output image
     * @param flags combination of interpolation methods (INTER_LINEAR or INTER_NEAREST) and the optional flag WARP_INVERSE_MAP, that sets M as the inverse transformation
     * @param borderMode pixel extrapolation method (BORDER_CONSTANT or BORDER_REPLICATE).
     * @param borderValue value used in case of a constant border; by default, it equals 0.
     */
    warpPerspective(
        src: CvMat,
        dst: CvMat,
        M: CvMat,
        size: CvSize,
        flags: InterpolationFlags,
        borderMode: BorderTypes.BORDER_CONSTANT | BorderTypes.BORDER_REPLICATE,
        borderValue: CvScalar
    ): void;
}
