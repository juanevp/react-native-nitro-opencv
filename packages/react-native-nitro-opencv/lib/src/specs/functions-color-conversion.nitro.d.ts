import { type HybridObject } from "react-native-nitro-modules";
import type { ColorConversionCodes } from "./constants-color-conversions-codes";
import type { CvMat } from "./mat.nitro";
export interface ColorConversion extends HybridObject<{
    ios: "c++";
    android: "c++";
}> {
    /**
     * Converts an image from one color space to another.
     * @param name Function name.
     * @param src input image: 8-bit unsigned, 16-bit unsigned ( CV_16UC... ), or single-precision floating-point.
     * @param dst output image of the same size and depth as src.
     * @param code color space conversion code.
     * @param dstCn number of channels in the destination image; if the parameter is 0, the number of the channels is derived automatically from src and code.
     */
    cvtColor(src: CvMat, dst: CvMat, code: ColorConversionCodes, dstCn?: number): void;
    /**
     * Converts an image from one color space to another where the source image is stored in two planes. This function only supports YUV420 to RGB conversion as of now.
     * @param name Function name.
     * @param src1 8-bit image (CV_8U) of the Y plane.
     * @param src2 image containing interleaved U/V plane.
     * @param dst output image.
     * @param code Specifies the type of conversion
     */
    cvtColorTwoPlane(src1: CvMat, src2: CvMat, dst: CvMat, code: ColorConversionCodes.COLOR_YUV2BGR_NV12 | ColorConversionCodes.COLOR_YUV2RGB_NV12 | ColorConversionCodes.COLOR_YUV2BGRA_NV12 | ColorConversionCodes.COLOR_YUV2RGBA_NV12 | ColorConversionCodes.COLOR_YUV2BGR_NV21 | ColorConversionCodes.COLOR_YUV2RGB_NV21 | ColorConversionCodes.COLOR_YUV2BGRA_NV21 | ColorConversionCodes.COLOR_YUV2RGBA_NV21): void;
    /**
     * main function for all demosaicing processes
     * @param name Function name.
     * @param src input image: 8-bit unsigned or 16-bit unsigned.
     * @param dst output image of the same size and depth as src.
     * @param code Color space conversion code (see the description below).
     * @param dstCn number of channels in the destination image
     */
    demosaicing(src: CvMat, dst: CvMat, code: ColorConversionCodes.COLOR_BayerBG2BGR | ColorConversionCodes.COLOR_BayerGB2BGR | ColorConversionCodes.COLOR_BayerRG2BGR | ColorConversionCodes.COLOR_BayerGR2BGR | ColorConversionCodes.COLOR_BayerBG2GRAY | ColorConversionCodes.COLOR_BayerGB2GRAY | ColorConversionCodes.COLOR_BayerRG2GRAY | ColorConversionCodes.COLOR_BayerGR2GRAY | ColorConversionCodes.COLOR_BayerBG2BGR_VNG | ColorConversionCodes.COLOR_BayerGB2BGR_VNG | ColorConversionCodes.COLOR_BayerRG2BGR_VNG | ColorConversionCodes.COLOR_BayerGR2BGR_VNG | ColorConversionCodes.COLOR_BayerBG2BGR_EA | ColorConversionCodes.COLOR_BayerGB2BGR_EA | ColorConversionCodes.COLOR_BayerRG2BGR_EA | ColorConversionCodes.COLOR_BayerGR2BGR_EA | ColorConversionCodes.COLOR_BayerBG2BGRA | ColorConversionCodes.COLOR_BayerGB2BGRA | ColorConversionCodes.COLOR_BayerRG2BGRA | ColorConversionCodes.COLOR_BayerGR2BGRA, dstCn?: number): void;
}
