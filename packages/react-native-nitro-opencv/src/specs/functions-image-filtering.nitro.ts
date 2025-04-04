import {type HybridObject} from "react-native-nitro-modules";

import type {BorderTypes} from "./constants-core";
import type {MorphShapes, MorphTypes} from "./constants-image-processing";
import type {DataTypes} from "./data-types";
import type {CvMat} from "./mat.nitro";
import type {CvPoint} from "./point.nitro";
import type {CvScalar} from "./scalar.nitro";
import type {CvSize} from "./size.nitro";

export interface ImageFiltering extends HybridObject<{ios: "c++"; android: "c++"}> {
    /**
     * Applies the bilateral filter to an image.
     * @param src Source 8-bit or floating-point, 1-channel or 3-channel image.
     * @param dst Destination image of the same size and type as src .
     * @param d Diameter of each pixel neighborhood that is used during filtering. If it is non-positive, it is computed from sigmaSpace.
     * @param sigmaColor Filter sigma in the color space. A larger value of the parameter means that farther colors within the pixel neighborhood (see sigmaSpace) will be mixed together, resulting in larger areas of semi-equal color.
     * @param sigmaSpace Filter sigma in the coordinate space. A larger value of the parameter means that farther pixels will influence each other as long as their colors are close enough (see sigmaColor ). When d>0, it specifies the neighborhood size regardless of sigmaSpace. Otherwise, d is proportional to sigmaSpace.
     * @param borderType border mode used to extrapolate pixels outside of the image, see BorderTypes
     */
    bilateralFilter(
        src: CvMat,
        dst: CvMat,
        d: number,
        sigmaColor: number,
        sigmaSpace: number,
        borderType: BorderTypes
    ): void;

    /**
     *
     * @param src input image; it can have any number of channels, which are processed independently, but the depth should be CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
     * @param dst output image of the same size and type as src.
     * @param ksize blurring kernel size.
     * @param anchor anchor point; default value Point(-1,-1) means that the anchor is at the kernel center.
     * @param borderType border mode used to extrapolate pixels outside of the image, see BorderTypes. BORDER_WRAP is not supported.
     */
    blur(src: CvMat, dst: CvMat, ksize: CvSize, anchor: CvPoint, borderType: BorderTypes): void;

    /**
     * Blurs an image using the box filter.
     * @param src input image.
     * @param dst output image of the same size and type as src.
     * @param ddepth the output image depth (-1 to use src.depth()).
     * @param ksize blurring kernel size.
     * @param anchor anchor point; default value Point(-1,-1) means that the anchor is at the kernel center.
     * @param normalize flag, specifying whether the kernel is normalized by its area or not.
     * @param borderType border mode used to extrapolate pixels outside of the image, see BorderTypes. BORDER_WRAP is not supported.
     */
    boxFilter(
        src: CvMat,
        dst: CvMat,
        ddepth: DataTypes,
        ksize: CvSize,
        anchor: CvPoint,
        normalize: boolean,
        borderType: BorderTypes
    ): void;

    /**
     * Constructs the Gaussian pyramid for an image.
     * @param src Source image. Check pyrDown for the list of supported types.
     * @param dst Destination vector of maxlevel+1 images of the same type as src. dst[0] will be the same as src. dst[1] is the next pyramid layer, a smoothed and down-sized src, and so on.
     * @param maxlevel 0-based index of the last (the smallest) pyramid layer. It must be non-negative.
     * @param borderType Pixel extrapolation method, see BorderTypes (BORDER_CONSTANT isn't supported)
     */
    buildPyramid(src: CvMat, dst: CvMat, maxlevel: number, borderType: BorderTypes): void;

    /**
     * Dilates an image by using a specific structuring element.
     * @param src input image; the number of channels can be arbitrary, but the depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F
     * @param dst output image of the same size and type as src.
     * @param kernel structuring element used for dilation; if elemenat=Mat(), a 3 x 3 rectangular structuring element is used. Kernel can be created using getStructuringElement
     * @param anchor position of the anchor within the element; default value (-1, -1) means that the anchor is at the element center.
     * @param iterations number of times dilation is applied.
     * @param borderType pixel extrapolation method, see BorderTypes. BORDER_WRAP is not suported.
     * @param borderValue border value in case of a constant border
     */
    dilate(
        src: CvMat,
        dst: CvMat,
        kernel: CvMat,
        anchor: CvPoint,
        iterations: number,
        borderType: BorderTypes,
        borderValue: CvScalar
    ): void;

    /**
     * Erodes an image by using a specific structuring element.
     * @param src input image; the number of channels can be arbitrary, but the depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F
     * @param dst output image of the same size and type as src.
     * @param kernel structuring element used for dilation; if elemenat=Mat(), a 3 x 3 rectangular structuring element is used. Kernel can be created using getStructuringElement
     * @param anchor position of the anchor within the element; default value (-1, -1) means that the anchor is at the element center.
     * @param iterations number of times dilation is applied.
     * @param borderType pixel extrapolation method, see BorderTypes. BORDER_WRAP is not suported.
     * @param borderValue border value in case of a constant border
     */
    erode(
        src: CvMat,
        dst: CvMat,
        kernel: CvMat,
        anchor: CvPoint,
        iterations: number,
        borderType: BorderTypes,
        borderValue: CvScalar
    ): void;

    /**
     * Convolves an image with the kernel.
     * @param src input image.
     * @param dst output image of the same size and the same number of channels as src.
     * @param ddepth desired depth of the destination image
     * @param kernel convolution kernel (or rather a correlation kernel), a single-channel floating point matrix; if you want to apply different kernels to different channels, split the image into separate color planes using split and process them individually.
     * @param anchor anchor of the kernel that indicates the relative position of a filtered point within the kernel; the anchor should lie within the kernel; default value (-1,-1) means that the anchor is at the kernel center.
     * @param delat optional value added to the filtered pixels before storing them in dst.
     * @param borderType pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
     */
    filter2D(
        src: CvMat,
        dst: CvMat,
        ddepth: number,
        kernel: CvMat,
        anchor: CvPoint,
        delat: number,
        borderType: BorderTypes
    ): void;

    /**
     * Blurs an image using a Gaussian filter.
     * @param src input image; the image can have any number of channels, which are processed independently, but the depth should be CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
     * @param dst output image of the same size and type as src.
     * @param ksize Gaussian kernel size. ksize.width and ksize.height can differ but they both must be positive and odd. Or, they can be zero's and then they are computed from sigma.
     * @param sigmaX Gaussian kernel standard deviation in X direction.
     * @param sigmaY Gaussian kernel standard deviation in Y direction; if sigmaY is zero, it is set to be equal to sigmaX, if both sigmas are zeros, they are computed from ksize.width and ksize.height, respectively (see getGaussianKernel for details); to fully control the result regardless of possible future modifications of all this semantics, it is recommended to specify all of ksize, sigmaX, and sigmaY.
     * @param borderType pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
     */
    GaussianBlur(
        src: CvMat,
        dst: CvMat,
        ksize: CvSize,
        sigmaX: number,
        sigmaY?: number,
        borderType?: BorderTypes
    ): void;

    /**
     *
     * @param ksize Size of the filter returned.
     * @param sigma Standard deviation of the gaussian envelope.
     * @param theta Orientation of the normal to the parallel stripes of a Gabor function.
     * @param lambd Wavelength of the sinusoidal factor.
     * @param gamma Spatial aspect ratio.
     * @param psi Phase offset.
     * @param ktype Type of filter coefficients. It can be CV_32F or CV_64F .
     */
    getGaborKernel(
        ksize: CvSize,
        sigma: number,
        theta: number,
        lambd: number,
        gamma: number,
        psi: number,
        ktype: DataTypes.Cv32F | DataTypes.Cv64F
    ): CvMat;

    /**
     * Returns Gaussian filter coefficients.
     * @param ksize Aperture size. It should be odd ( 𝚔𝚜𝚒𝚣𝚎mod2=1 ) and positive.
     * @param sigma Gaussian standard deviation. If it is non-positive, it is computed from ksize as sigma = 0.3*((ksize-1)*0.5 - 1) + 0.8.
     * @param ktype Type of filter coefficients. It can be CV_32F or CV_64F .
     */
    getGaussianKernel(ksize: number, sigma: number, ktype: DataTypes.Cv32F | DataTypes.Cv64F): CvMat;

    /**
     * Returns a structuring element of the specified size and shape for morphological operations.
     * @param shape Element shape that could be one of MorphShapes
     * @param ksize Size of the structuring element.
     * @param anchor Anchor position within the element. The default value means that the anchor is at the center. Note that only the shape of a cross-shaped element depends on the anchor position. In other cases the anchor just regulates how much the result of the morphological operation is shifted.
     */
    getStructuringElement(shape: MorphShapes, ksize: CvSize, anchor?: CvPoint): CvMat;

    /**
     * Calculates the Laplacian of an image.
     * @param name Function name.
     * @param src Source image.
     * @param dst Destination image of the same size and the same number of channels as src .
     * @param ddepth Desired depth of the destination image.
     * @param ksize Aperture size used to compute the second-derivative filters. See getDerivKernels for details. The size must be positive and odd.
     * @param scale Optional scale factor for the computed Laplacian values. By default, no scaling is applied. See getDerivKernels for details.
     * @param delta Optional delta value that is added to the results prior to storing them in dst
     * @param borderType Pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
     */
    Laplacian(
        src: CvMat,
        dst: CvMat,
        ddepth: DataTypes,
        ksize: number,
        scale: number,
        delta: number,
        borderType: BorderTypes
    ): void;

    /**
     * Blurs an image using the median filter.
     * The function smoothes an image using the median filter with the 𝚔𝚜𝚒𝚣𝚎×𝚔𝚜𝚒𝚣𝚎 aperture. Each channel of a multi-channel image is processed independently. In-place operation is supported.
     * @param name Function name.
     * @param src input 1-, 3-, or 4-channel image; when ksize is 3 or 5, the image depth should be CV_8U, CV_16U, or CV_32F, for larger aperture sizes, it can only be CV_8U.
     * @param dst destination array of the same size and type as src.
     * @param ksize aperture linear size; it must be odd and greater than 1, for example: 3, 5, 7 ...
     */
    medianBlur(src: CvMat, dst: CvMat, ksize: number): void;

    /**
     * returns "magic" border value for erosion and dilation. It is automatically transformed to Scalar::all(-DBL_MAX) for dilation.
     */
    morphologyDefaultBorderValue(): CvScalar;

    /**
     * Performs advanced morphological transformations.
     * The function cv::morphologyEx can perform advanced morphological transformations using an erosion and dilation as basic operations.
     * Any of the operations can be done in-place. In case of multi-channel images, each channel is processed independently.
     * @param name Function name.
     * @param src Source image. The number of channels can be arbitrary. The depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
     * @param dst Destination image of the same size and type as source image.
     * @param op Type of a morphological operation, see MorphTypes
     * @param kernel Structuring element. It can be created using getStructuringElement.
     * @param anchor Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.
     * @param iterations Number of times erosion and dilation are applied.
     * @param borderType Pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
     * @param borderValue Border value in case of a constant border. The default value has a special meaning.
     */
    morphologyEx(
        src: CvMat,
        dst: CvMat,
        op: MorphTypes,
        kernel: CvMat,
        anchor?: CvPoint,
        iterations?: number,
        borderType?: BorderTypes,
        borderValue?: CvScalar
    ): void;

    /**
     * Calculates the first, second, third, or mixed image derivatives using an extended Sobel operator.
     * @param name Function name.
     * @param src input image.
     * @param dst output image of the same size and the same number of channels as src .
     * @param ddepth output image depth, see combinations; in the case of 8-bit input images it will result in truncated derivatives.
     * @param dx order of the derivative x.
     * @param dy order of the derivative y.
     * @param ksize size of the extended Sobel kernel; it must be 1, 3, 5, or 7.
     * @param scale scale factor for the computed derivative values; by default, no scaling is applied (see getDerivKernels for details).
     * @param delta delta value that is added to the results prior to storing them in dst.
     * @param borderType Pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
     */
    Sobel(
        src: CvMat,
        dst: CvMat,
        ddepth: number,
        dx: number,
        dy: number,
        ksize: 1 | 3 | 5 | 7,
        scale: number,
        delta: number,
        borderType: Exclude<BorderTypes, BorderTypes.BORDER_WRAP>
    ): void;
}
