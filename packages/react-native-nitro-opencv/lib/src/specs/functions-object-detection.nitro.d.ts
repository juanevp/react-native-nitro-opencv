import { type HybridObject } from "react-native-nitro-modules";
import type { TemplateMatchModes } from "./constants-image-processing";
import type { CvMat } from "./mat.nitro";
import type { CvPoint2f } from "./point.nitro";
export interface PhaseCorrelationResult {
    phaseShift: CvPoint2f;
    response: number;
}
export interface ObjectDetection extends HybridObject<{
    ios: "c++";
    android: "c++";
}> {
    /**
     * Compares a template against overlapped image regions
     * @param name Function name
     * @param image Image where the search is running. It must be 8-bit or 32-bit floating-point
     * @param templ Searched template. It must be not greater than the source image and have the same data type.
     * @param result Map of comparison results. It must be single-channel 32-bit floating-point. If image is W×H and templ is w×h , then result is (W−w+1)×(H−h+1) .
     * @param method Parameter specifying the comparison method, @see TemplateMatchModes
     * @param mask Mask of searched template. It must have the same datatype and size with templ. It is not set by default. Currently, only the TM_SQDIFF and TM_CCORR_NORMED methods are supported
     */
    matchTemplate(image: CvMat, templ: CvMat, result: CvMat, method: TemplateMatchModes, mask: CvMat): void;
    /**
     * The function is used to detect translational shifts that occur between two images.
     * The operation takes advantage of the Fourier shift theorem for detecting the translational shift
     * in the frequency domain. It can be used for fast image registration as well as motion estimation.
     *
     * For more information please see http://en.wikipedia.org/wiki/Phase_correlation
     *
     * @param name Function name
     * @param src1 Source floating point array (CV_32FC1 or CV_64FC1)
     * @param src2 Source floating point array (CV_32FC1 or CV_64FC1)
     * @param window Floating point array with windowing coefficients to reduce edge effects (optional).
     */
    phaseCorrelate(src1: CvMat, src2: CvMat, window?: CvMat): PhaseCorrelationResult;
}
