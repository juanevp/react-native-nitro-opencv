import {type HybridObject} from "react-native-nitro-modules";

import type {
    BorderTypes,
    CmpTypes,
    CovarFlags,
    DecompTypes,
    DftFlags,
    GemmFlags,
    NormTypes,
    ReduceTypes,
    RotateFlags,
    SortFlags,
} from "./constants-core";
import type {DataTypes} from "./data-types";
import type {MatVector} from "./mat-vector.nitro";
import type {CvMat} from "./mat.nitro";
import type {PointVector} from "./point-vector.nitro";
import type {CvPoint, CvPoint2f} from "./point.nitro";
import type {CvRect} from "./rect.nitro";
import type {CvScalar} from "./scalar.nitro";

export interface Core extends HybridObject<{ios: "c++"; android: "c++"}> {
    /**
     * Calculates the per-element absolute difference between two arrays or between an array and a scalar.
     * @param name Function name.
     * @param src1 first input array.
     * @param src2 second input array.
     * @param dst output array that has the same size and type as input arrays.
     */
    absdiff(src1: CvMat, src2: CvMat, dst: CvMat): void;

    /**
     * @param name Function name.
     * @param src1 first input array.
     * @param src2 second input array.
     * @param dst output array that has the same size and type as input arrays.
     * @param mask optional operation mask - 8-bit single channel array, that specifies elements of the output array to be changed.
     * @param dtype optional depth of the output array.
     */
    add(src1: CvMat, src2: CvMat, dst: CvMat, mask?: CvMat, dtype?: DataTypes): void;

    /**
     * @param name Function name.
     * @param src1 first input array.
     * @param alpha weight of the first array elements.
     * @param src2 second input array of the same size and channel number as src1.
     * @param beta weight of the second array elements.
     * @param gamma scalar added to each sum.
     * @param dst output array that has the same size and number of channels as the input arrays.
     * @param dtype optional depth of the output array; when both input arrays have the same depth, dtype can be set to -1, which will be equivalent to src1.depth().
     */
    addWeighted(src1: CvMat, alpha: number, src2: CvMat, beta: number, gamma: number, dst: CvMat, dtype?: DataTypes): void;

    /**
     * naive nearest neighbor finder
     * @todo document when it's updated in opencv documentation
     */
    batchDistance(
        src1: CvMat,
        src2: CvMat,
        dist: CvMat,
        dtype: number | DataTypes,
        nidx: CvMat,
        normType: NormTypes,
        K: number,
        mask: CvMat,
        update: number,
        crosscheck: boolean
    ): void;

    /**
     * computes bitwise conjunction of the two arrays (dst = src1 & src2) Calculates the per-element bit-wise conjunction of two arrays or an array and a scalar.
     * @param name Function name.
     * @param src1 first input array or a scalar.
     * @param src2 second input array or a scalar.
     * @param dst output array that has the same size and type as the input arrays.
     * @param mask optional operation mask, 8-bit single channel array, that specifies elements of the output array to be changed.
     */
    bitwise_and(src1: CvMat, src2: CvMat, dst: CvMat, mask?: CvMat): void;
    /**
     * Inverts every bit of an array.
     * @param name Function name.
     * @param src input array.
     * @param dst output array that has the same size and type as the input array.
     * @param mask optional operation mask, 8-bit single channel array, that specifies elements of the output array to be changed.
     */
    bitwise_not(src: CvMat, dst: CvMat, mask?: CvMat): void;
    /**
     * Calculates the per-element bit-wise disjunction of two arrays or an array and a scalar.
     * @param name Function name.
     * @param src1 first input array or a scalar.
     * @param src2 second input array or a scalar.
     * @param dst output array that has the same size and type as the input arrays.
     * @param mask optional operation mask, 8-bit single channel array, that specifies elements of the output array to be changed.
     */
    bitwise_or(src1: CvMat, src2: CvMat, dst: CvMat, mask?: CvMat): void;
    /**
     * Calculates the per-element bit-wise "exclusive or" operation on two arrays or an array and a scalar.
     * @param name Function name.
     * @param src1 first input array or a scalar.
     * @param src2 second input array or a scalar.
     * @param dst output array that has the same size and type as the input arrays.
     * @param mask optional operation mask, 8-bit single channel array, that specifies elements of the output array to be changed.
     */
    bitwise_xor(src1: CvMat, src2: CvMat, dst: CvMat, mask?: CvMat): void;

    /**
     * Computes the source location of an extrapolated pixel.
     * @param p 0-based coordinate of the extrapolated pixel along one of the axes, likely <0 or >= len
     * @param len Length of the array along the corresponding axis.
     * @param borderType Border type, one of the BorderTypes, except for BORDER_TRANSPARENT and BORDER_ISOLATED . When borderType==BORDER_CONSTANT , the function always returns -1, regardless of p and len
     */
    borderInterpolate(p: number, len: number, borderType: BorderTypes): number;

    /**
     * Calculates the covariance matrix of a set of vectors.
     * @param name Function name.
     * @param samples samples stored as separate matrices
     * @param nsamples number of samples
     * @param covar output covariance matrix of the type ctype and square size.
     * @param mean input or output (depending on the flags) array as the average value of the input vectors.
     * @param flags operation flags as a combination of CovarFlags
     * @param ctype type of the matrix
     */
    calcCovarMatrix(
        samples: MatVector,
        nsamples: number,
        covar: CvMat,
        mean: CvMat,
        flags: CovarFlags,
        ctype: DataTypes
    ): void;

    /**
     * Calculates the magnitude and angle of 2D vectors.
     * @param name Function name.
     * @param x array of x-coordinates; this must be a single-precision or double-precision floating-point array
     * @param y array of y-coordinates, that must have the same size and same type as x.
     * @param magnitude output array of magnitudes of the same size and type as x
     * @param angle output array of angles that has the same size and type as x; the angles are measured in radians (from 0 to 2*Pi) or in degrees (0 to 360 degrees).
     * @param angleInDegrees flag, indicating whether the angles are measured in radians (which is by default), or in degrees.
     */
    cartToPolar(x: CvMat, y: CvMat, magnitude: CvMat, angle: CvMat, angleInDegrees?: boolean): void;
    cartToPolarN(x: MatVector, y: MatVector, magnitude: MatVector, angle: MatVector, angleInDegrees?: boolean): void;

    /**
     * Checks every element of an input array for invalid values.
     * @param name Function name.
     * @param a input array.
     * @param quiet a flag, indicating whether the functions quietly return false when the array elements are out of range or they throw an exception
     * @param pos output parameter, when not NULL, must be a pointer to array of src.dims elements.
     * @param minVal inclusive lower boundary of valid values range.
     * @param maxVal exclusive upper boundary of valid values range.
     */
    checkRange(a: MatVector | CvMat, quiet: boolean, pos: CvPoint | undefined, minVal: number, maxVal: number): void;

    /**
     * Performs the per-element comparison of two arrays or an array and scalar value
     * @param name Function name.
     * @param src1 first input array or a scalar; when it is an array, it must have a single channel
     * @param src2 second input array or a scalar; when it is an array, it must have a single channel
     * @param dst output array of type ref CV_8U that has the same size and the same number of channels as the input arrays
     * @param cmpopa flag, that specifies correspondence between the arrays (cv.CmpTypes)
     */
    compare(src1: CvMat, src2: CvMat, dst: CvMat, cmpop: CmpTypes): void;

    /**
     * @param name Function name.
     * Copies the lower or the upper half of a square matrix to its another half.
     * @param m input-output floating-point square matrix
     * @param lowerToUpper operation flag; if true, the lower half is copied to the upper half. Otherwise, the upper half is copied to the lower half.
     */
    completeSymm(m: MatVector | CvMat, lowerToUpper: boolean): void;

    /**
     * Converts an array to half precision floating number.\
     * @param name Function name.
     * @param src input array
     * @param dst output array
     */
    convertFp16(src: CvMat, dst: CvMat): void;

    /**
     * Scales, calculates absolute values, and converts the result to 8-bit.
     * @param name Function name.
     * @param src input array
     * @param dst output array
     * @param alpha optional scale factor
     * @param beta optional delta added to the scaled values
     */
    convertScaleAbs(src: CvMat, dst: CvMat, alpha?: number, beta?: number): void;

    /**
     * Forms a border around an image.
     * @param name Function name.
     * @param src Source image
     * @param dst Destination image of the same type as src and the size Size(src.cols+left+right, src.rows+top+bottom)
     * @param top the top pixels
     * @param bottom the bottom pixels
     * @param left the left pixels
     * @param right Parameter specifying how many pixels in each direction from the source image rectangle to extrapolate. For example, top=1, bottom=1, left=1, right=1 mean that 1 pixel-wide border needs to be built
     * @param borderType Border type. See borderInterpolate for details
     * @param value Border value if borderType==BORDER_CONSTANT
     */
    copyMakeBorder(
        src: CvMat,
        dst: CvMat,
        top: number,
        bottom: number,
        left: number,
        right: number,
        borderType: BorderTypes,
        value: CvScalar
    ): void;

    /**
     * This is an overloaded member function, provided for convenience (python) Copies the matrix to another one.
     * @param name Function name.
     * @param src source matrix
     * @param dst Destination matrix. If it does not have a proper size or type before the operation, it is reallocated
     * @param mask Operation mask of the same size as *this. Its non-zero elements indicate which matrix elements need to be copied. The mask has to be of type CV_8U and can have 1 or multiple channels
     */
    copyTo(src: CvMat, dst: CvMat, mask: CvMat): void;

    /**
     * Counts non-zero array elements.
     * @param name Function name.
     * @param src single-channel array
     * @returns the number of non-zero elements in src
     */
    countNonZero(src: MatVector | CvMat): number;

    /**
     * This functions allows to crop Mat to selected size using Rect.
     * @param name Function name.
     * @param src Source matrix
     * @param dst Destination matrix. If it does not have a proper size or type before the operation, it is reallocated
     * @param roi Rectangle as ROI
     */
    crop(src: CvMat, dst: CvMat, roi: CvRect): void;

    /**
     * Performs a forward or inverse discrete Cosine transform of 1D or 2D array.
     * @param name Function name.
     * @param src input floating-point array
     * @param dst output array of the same size and type as src
     * @param flags transformation flags as a combination of cv.DftFlags (DCT_*)
     */
    dct(src: CvMat, dst: CvMat, flags: DftFlags): void;

    /**
     * Returns the determinant of a square floating-point matrix.
     * @param name Function name.
     * @param src input matrix that must have CV_32FC1 or CV_64FC1 type and square size.
     * @returns the determinant of the specified matrix
     */
    determinant(src: CvMat): number;

    /**
     * Performs a forward or inverse Discrete Fourier transform of a 1D or 2D floating-point array.
     * @param name Function name.
     * @param src input array that could be real or complex
     * @param dst output array whose size and type depends on the flags
     * @param flags transformation flags, representing a combination of the DftFlags
     * @param nonzeroRows when the parameter is not zero, the function assumes that only the first nonzeroRows rows of
     * the input array (DFT_INVERSE is not set) or only the first nonzeroRows of the output array (DFT_INVERSE is set)
     * contain non-zeros, thus, the function can handle the rest of the rows more efficiently and save some time; this
     * technique is very useful for calculating array cross-correlation or convolution using DFT.
     */
    dft(src: CvMat, dst: CvMat, flags: DftFlags, nonzeroRows: number): void;

    /**
     * @param name Function name.
     * @param src1 first input array.
     * @param src2 second input array of the same size and type as src1.
     * @param dst output array of the same size and type as src2.
     * @param scale scalar factor
     * @param dtype optional depth of the output array; if -1, dst will have depth src2.depth(), but in case of an array-by-array division, you can only pass -1 when src1.depth()==src2.depth().
     */
    divide(src1: CvMat, src2: CvMat, dst: CvMat, scale: number, dtype?: number): void;

    /**
     * Calculates eigenvalues and eigenvectors of a symmetric matrix
     * @param name Function name.
     * @param src input matrix that must have CV_32FC1 or CV_64FC1 type, square size and be symmetrical (src ^T^ == src)
     * @param eigenvalues output vector of eigenvalues of the same type as src; the eigenvalues are stored in the descending order
     * @param eigenvectors output matrix of eigenvectors; it has the same size and type as src; the eigenvectors are stored as subsequent matrix rows, in the same order as the corresponding eigenvalues
     */
    eigen(src: CvMat, eigenvalues: CvMat, eigenvectors: CvMat): void;

    /**
     * Calculates eigenvalues and eigenvectors of a non-symmetric matrix (real eigenvalues only)
     * @param name Function name.
     * @param src input matrix (CV_32FC1 or CV_64FC1 type)
     * @param eigenvalues output vector of eigenvalues (type is the same type as src)
     * @param eigenvectors output matrix of eigenvectors (type is the same type as src). The eigenvectors are stored as subsequent matrix rows, in the same order as the corresponding eigenvalues
     */
    eigenNonSymmetric(src: CvMat, eigenvalues: CvMat, eigenvectors: CvMat): void;

    /**
     * Calculates the exponent of every array element.
     * @param name Function name.
     * @param src input array
     * @param dst output array of the same size and type as src
     */
    exp(src: CvMat, dst: CvMat): void;

    /**
     * Extracts a single channel from src (coi is 0-based index)
     * @param name Function name.
     * @param src input array
     * @param dst output array
     * @param coi index of channel to extract
     */
    extractChannel(src: CvMat, dst: CvMat, coi: number): void;

    /**
     * Returns the list of locations of non-zero pixels
     * @param name Function name.
     * @param src single-channel array
     * @param idx the output array, type of cv.Mat or Array<Point>, corresponding to non-zero indices in the input
     */
    findNonZero(src: CvMat, idx: CvMat | PointVector): void;

    /**
     * Flips a 2D array around vertical, horizontal, or both axes
     * @param name Function name.
     * @param src input array
     * @param dst output array of the same size and type as src
     * @param flipCode a flag to specify how to flip the array; 0 means flipping around the x-axis and positive value (for example, 1) means flipping around y-axis. Negative value (for example, -1) means flipping around both axes
     */
    flip(src: CvMat, dst: CvMat, flipCode: number): void;

    /**
     * Performs generalized matrix multiplication
     * @param name Function name.
     * @param src1 first multiplied input matrix that could be real(CV_32FC1, CV_64FC1) or complex(CV_32FC2, CV_64FC2)
     * @param src2 second multiplied input matrix of the same type as src1
     * @param alpha weight of the matrix product
     * @param src3 third optional delta matrix added to the matrix product; it should have the same type as src1 and src2.
     * @param beta weight of src3
     * @param dst output matrix; it has the proper size and the same type as input matrices
     * @param flags operation flags (cv.GemmFlags)
     */
    gemm(src1: CvMat, src2: CvMat, alpha: number, src3: CvMat, beta: number, dst: CvMat, flags: GemmFlags): void;

    /**
     * Calculates the optimal DFT size for a given vector size.
     * @param name Function name.
     * @param vecsize vector size
     * @returns the optimal DFT size for a given vector size.
     */
    getOptimalDFTSize(vecsize: number): number;

    /**
     * Calculates rotation matrix.
     * @param name Function name.
     * @param center center point
     * @param angle angle value
     * @param scale scale value
     * @param dst output matrix
     */
    getRotationMatrix2D(center: CvPoint2f, angle: number, scale: number, dst: CvMat): void;

    /**
     * Applies horizontal concatenation to given matrices
     * @param name Function name.
     * @param src input array or vector of matrices. all of the matrices must have the same number of rows and the same depth
     * @param dst output array. It has the same number of rows and depth as the src, and the sum of cols of the src
     */

    hconcat(srcs: MatVector, dst: CvMat): void;

    /**
     * Calculates the inverse Discrete Fourier Transform of a 1D or 2D array
     * @param name Function name.
     * @param src input floating-point real or complex array
     * @param dst output array whose size and type depend on the flags
     * @param flags operation flags (see dft and DftFlags).
     * @param nonzeroRows number of dst rows to process
     */
    idft(src: CvMat, dst: CvMat, flags: DftFlags, nonzeroRows: number): void;

    /**
     * Checks if array elements lie between the elements of two other arrays.
     * @param name Function name.
     * @param src first input array
     * @param lowerb inclusive lower boundary scalar
     * @param upperb inclusive upper boundary scalar
     * @param dst output array of the same size as src and CV_8U type
     */
    inRange(src: CvMat, lowerb: CvScalar, upperb: CvScalar, dst: CvMat): void;

    /**
     * Inserts a single channel to dst (coi is 0-based index)
     * @param name Function name.
     * @param src input array
     * @param dst output array
     * @param coi 0-based index
     */
    insertChannel(src: CvMat, dst: CvMat, coi: number): void;

    /**
     * Finds the inverse or pseudo-inverse of a matrix.
     * @param name Function name.
     * @param src input floating-point M x N matrix
     * @param dst output matrix of N x M size and the same type as src
     * @param flags inversion method (cv.DecompTypes)
     */
    invert(src: CvMat, dst: CvMat, flags: DecompTypes): void;

    /**
     * Calculates the natural logarithm of every array element
     * @param name Function name.
     * @param src input array
     * @param dst output array of the same size and type as src
     */
    log(src: CvMat, dst: CvMat): void;

    /**
     * Performs a look-up table transform of an array
     * @param name Function name.
     * @param src input array of 8-bit elements
     * @param lut look-up table of 256 elements; in case of multi-channel input array, the table should either have a single channel (in this case the same table is used for all channels) or the same number of channels as in the input array
     * @param dst output array of the same size and number of channels as src, and the same depth as lut
     */
    LUT(src: CvMat, lut: CvMat, dst: CvMat): void;

    /**
     * Calculates the magnitude of 2D vectors
     * @param name Function name.
     * @param x floating-point array of x-coordinates of the vectors
     * @param y floating-point array of y-coordinates of the vectors; it must have the same size as x.
     * @param magnitude output array of the same size and type as x
     */
    magnitude(x: CvMat, y: CvMat, magnitude: CvMat): void;
    magnitudeN(x: MatVector, y: MatVector, magnitude: CvMat): void;

    /**
     * Calculates the Mahalanobis distance between two vectors
     * @param name Function name.
     * @param v1 first 1D input vector
     * @param v2 second 1D input vector
     * @param icovar inverse covariance matrix
     */
    Mahalanobis(v1: CvMat, v2: CvMat, icovar: CvMat): void;
    MahalanobisN(v1: MatVector, v2: MatVector, icovar: CvMat): void;

    /**
     * Calculates per-element maximum of two arrays or an array and a scalar
     * @param name Function name.
     * @param src1 first input array
     * @param src2 second input array of the same size and type as src1
     * @param dst output array of the same size and type as src1
     */
    max(src1: CvMat, src2: CvMat, dst: CvMat): void;

    /**
     * Calculates an average (mean) of array elements
     * @param name Function name.
     * @param src input array that should have from 1 to 4 channels so that the result can be stored in Scalar
     * @param mask optional operation mask
     * @returns a Scalar which contains the average of each channel
     */
    mean(src: CvMat, mask?: CvMat): CvScalar;

    /**
     * Calculates a mean and standard deviation of array elements
     * @param name Function name.
     * @param src input array that should have from 1 to 4 channels so that the results can be stored in Scalar
     * @param mean output parameter: calculated mean value
     * @param stddev output parameter: calculated standard deviation
     * @param mask optional operation mask
     */
    meanStdDev(src: CvMat, mean: CvMat, stddev: CvMat, mask?: CvMat): void;

    /**
     * This is an overloaded member function, provided for convenience.
     * @param name Function name.
     * @param mv input vector of matrices to be merged; all the matrices in mv must have the same size and the same depth
     * @param dst output array of the same size and the same depth as mv[0]; The number of channels will be the total number of channels in the matrix array
     */
    merge(mv: MatVector, dst: CvMat): void;

    /**
     * Calculates per-element minimum of two arrays or an array and a scalar
     * @param name Function name.
     * @param src1 first input array
     * @param src2 second input array of the same size and type as src1
     * @param dst output array of the same size and type as src1
     */
    min(src1: CvMat, src2: CvMat, dst: CvMat): void;

    /**
     * Finds the global minimum and maximum in an array
     * @param name Function name.
     * @param src input single-channel array
     * @param mask optional mask used to select a sub-array
     * @returns a tuple with the minimum as the first element and the maximum as the second
     */
    minMaxLoc(src: CvMat, mask?: CvMat): [number, number];

    /**
     * Performs the per-element multiplication of two Fourier spectrums
     * @param name Function name.
     * @param a first input array
     * @param b second input array of the same size and type as src1
     * @param c output array of the same size and type as src1 .
     * @param flags operation flags; currently, the only supported flag is cv.DFT_ROWS, which indicates that each row of src1 and src2 is an independent 1D Fourier spectrum. If you do not want to use this flag, then simply add a 0 as value.
     * @param conjB optional flag that conjugates the second input array before the multiplication (true) or not (false).
     */
    mulSpectrums(a: CvMat, b: CvMat, c: CvMat, flags: DftFlags, conjB?: boolean): void;

    /**
     * Calculates the per-element scaled product of two arrays
     * @param name Function name.
     * @param src1 first input array
     * @param src2 second input array of the same size and the same type as src1
     * @param dst output array of the same size and type as src1
     * @param scale optional scale factor
     * @param dtype optional depth of the output array
     */
    multiply(src1: CvMat, src2: CvMat, dst: CvMat, scale: number, dtype?: DataTypes): void;

    /**
     * Calculates the product of a matrix and its transposition
     * @param name Function name.
     * @param src input single-channel matrix. Note that unlike gemm, the function can multiply not only floating-point matrices
     * @param dst output square matrix
     * @param aTa Flag specifying the multiplication ordering. See the description below
     * @param delta Optional delta matrix subtracted from src before the multiplication. When the matrix is empty ( delta=noArray() ), it is assumed to be zero, that is, nothing is subtracted. If it has the same size as src , it is simply subtracted. Otherwise, it is "repeated" (see repeat ) to cover the full src and then subtracted. Type of the delta matrix, when it is not empty, must be the same as the type of created output matrix. See the dtype parameter description below
     * @param scale Optional scale factor for the matrix product.
     * @param dtype Optional type of the output matrix. When it is negative, the output matrix will have the same type as src
     */
    mulTransposed(src: CvMat, dst: CvMat, aTa: boolean, delta: CvMat, scale: number, dtype?: DataTypes): void;

    /**
     * Calculates the absolute norm of an array
     * @param name Function name.
     * @param src first input array
     * @param normType type of the norm (see cv.NormTypes).
     * @param mask optional operation mask; it must have the same size as src1 and CV_8UC1 type.
     * @returns the absolute norm of an array
     */
    norm(src: CvMat, normType: NormTypes, mask?: CvMat): number;

    /**
     * Normalizes the norm or value range of an array.
     * @param name Function name.
     * @param src input array
     * @param dst output array of the same size as src
     * @param alpha norm value to normalize to or the lower range boundary in case of the range normalization
     * @param normType normalization type (see cv::NormTypes).
     */
    normalize(src: CvMat, dst: CvMat, alpha: number, normType: NormTypes): void;

    /**
     * converts NaNs to the given number
     * @param name Function name.
     * @param a input/output matrix (CV_32F type).
     * @param val value to convert the NaNs
     */
    patchNaNs(a: CvMat | MatVector, val: number): void;

    /**
     * Performs the perspective matrix transformation of vectors
     * @param name Function name.
     * @param src input two-channel or three-channel floating-point array; each element is a 2D/3D vector to be transformed
     * @param dst output array of the same size and type as src
     * @param m 3x3 or 4x4 floating-point transformation matrix.
     */
    perspectiveTransform(src: CvMat, dst: CvMat, m: CvMat): void;

    /**
     * Calculates the rotation angle of 2D vectors
     * @param name Function name.
     * @param x input floating-point array of x-coordinates of 2D vectors
     * @param y input array of y-coordinates of 2D vectors; it must have the same size and the same type as x
     * @param angle output array of vector angles; it has the same size and same type as x
     * @param angleInDegrees when true, the function calculates the angle in degrees, otherwise, they are measured in radians
     */
    phase(x: CvMat, y: CvMat, angle: CvMat, angleInDegrees: boolean): void;
    phaseN(x: MatVector, y: MatVector, angle: CvMat, angleInDegrees: boolean): void;

    /**
     * Raises every array element to a power
     * @param name Function name.
     * @param src input array
     * @param power exponent of power
     * @param dst output array of the same size and type as src
     */
    pow(src: CvMat, power: number, dst: CvMat): void;

    /**
     * Computes the Peak Signal-to-Noise Ratio (PSNR) image quality metric
     * @param name Function name.
     * @param src1 first input array
     * @param src2 second input array of the same size as src1
     * @param R the maximum pixel value (255 by default)
     * @returns the Peak Signal-to-Noise Ratio (PSNR) image quality metric in decibels (dB)
     */
    PSNR(src1: CvMat, src2: CvMat, R: number): number;

    /**
     * Reduces a matrix to a vector.
     * @param name Function name.
     * @param src input 2D matrix
     * @param dst output vector. Its size and type is defined by dim and dtype parameters
     * @param dim dimension index along which the matrix is reduced. 0 means that the matrix is reduced to a single row. 1 means that the matrix is reduced to a single column
     * @param rtype reduction operation that could be one of ReduceTypes
     * @param dtype when negative, the output vector will have the same type as the input matrix, otherwise, its type will be CV_MAKE_TYPE(CV_MAT_DEPTH(dtype), src.channels())
     */
    reduce(src: CvMat, dst: CvMat, dim: number, rtype: ReduceTypes, dtype: DataTypes): void;

    /**
     * Fills the output array with repeated copies of the input array
     * @param name Function name.
     * @param src input array to replicate
     * @param ny Flag to specify how many times the src is repeated along the vertical axis
     * @param nx Flag to specify how many times the src is repeated along the horizontal axis
     * @param dst output array of the same type as src.
     */
    repeat(src: CvMat, ny: number, nx: number, dst: CvMat): void;

    /**
     * Rotates matrix.
     * @param name Function name.
     * @param src input array to replicate
     * @param dst output array of the same type as src
     * @param code rotate flag
     */
    rotate(src: CvMat, dst: CvMat, code: RotateFlags): void;

    /**
     * Calculates the sum of a scaled array and another array
     * @param name Function name.
     * @param src1 first input array.
     * @param alpha scale factor for the first array
     * @param src2 second input array of the same size and type as src1
     * @param dst output array of the same size and type as src1
     */
    scaleAdd(src1: CvMat, alpha: number, src2: CvMat, dst: CvMat): void;

    /**
     * Solves one or more linear systems or least-squares problems
     * @param name Function name.
     * @param src1 input matrix on the left-hand side of the system
     * @param src2 input matrix on the right-hand side of the system
     * @param dst output solution
     * @param flags solution (matrix inversion) method (DecompTypes)
     */
    solve(src1: CvMat, src2: CvMat, dst: CvMat, flags: DecompTypes): boolean;

    /**
     * Finds the real roots of a cubic equation
     * @param name Function name.
     * @param coeffs equation coefficients, an array of 3 or 4 elements
     * @param roots output array of real roots that has 1 or 3 elements
     */
    solveCubic(coeffs: CvMat, roots: CvMat): boolean;

    /**
     * Finds the real or complex roots of a polynomial equation
     * @param name Function name.
     * @param src array of polynomial coefficients
     * @param dst output (complex) array of roots
     * @param maxIters maximum number of iterations the algorithm does
     */
    solvePoly(src: CvMat, dst: CvMat, maxIters?: number): number;

    /**
     * Sorts each row or each column of a matrix.
     * @param name Function name.
     * @param src input single-channel array
     * @param dst output array of the same size and type as src.
     * @param flags operation flags, a combination of SortFlags
     */
    sort(src: CvMat, dst: CvMat, flags: SortFlags): void;

    /**
     * Sorts each row or each column of a matrix
     * @param name Function name.
     * @param src input single-channel array
     * @param dst output array of the same size and type as src.
     * @param flags operation flags, a combination of SortFlags
     */
    sortIdx(src: CvMat, dst: CvMat, flags: SortFlags): void;

    /**
     * Divides a multi-channel array into several single-channel arrays
     * @param name Function name.
     * @param src input multi-channel array.
     * @param dst output vector of arrays; the arrays themselves are reallocated, if needed.
     */
    split(src: CvMat, dst: MatVector): void;

    /**
     * Calculates a square root of array elements
     * @param name Function name.
     * @param src input floating-point array.
     * @param dst output array of the same size and type as src
     */
    sqrt(src: CvMat, dst: CvMat): void;

    /**
     * @param name Function name.
     * @param src1 first input array or a scalar
     * @param src2 second input array or a scalar
     * @param dst output array of the same size and the same number of channels as the input array
     * @param mask optional operation mask; this is an 8-bit single channel array that specifies elements of the output array to be changed
     * @param dtype optional depth of the output array
     */
    subtract(src1: CvMat, src2: CvMat, dst: CvMat, mask?: CvMat, dtype?: DataTypes): void;

    /**
     * Calculates the sum of array elements
     * @param name Function name.
     * @param src input array that must have from 1 to 4 channels
     */
    sum(src: MatVector | CvMat): CvScalar;

    /**
     * Returns the trace of a matrix
     * @param name Function name.
     * @param mtx input matrix
     */
    trace(mtx: CvMat): CvScalar;

    /**
     * Performs the matrix transformation of every array element
     * @param name Function name.
     * @param src input array that must have as many channels (1 to 4) as m.cols or m.cols-1.
     * @param dst output array of the same size and depth as src; it has as many channels as m.rows
     * @param m transformation 2x2 or 2x3 floating-point matrix
     */
    transform(src: CvMat, dst: CvMat, m: CvMat): void;

    /**
     * Transposes a matrix
     * @param name Function name.
     * @param src input array.
     * @param dst output array of the same type as src
     */
    transpose(src: CvMat, dst: CvMat): void;

    /**
     * Applies vertical concatenation to given matrices
     * @param name Function name.
     * @param src input array or vector of matrices. all of the matrices must have the same number of cols and the same depth
     * @param dst output array. It has the same number of cols and depth as the src, and the sum of rows of the src. same depth
     */
    vconcat(src: MatVector, dst: CvMat): void;

    /**
     * Converts an array to another data type with optional scaling.
     * @param name Function name.
     * @param src input matrix.
     * @param dst output matrix; if it does not have a proper size or type before the operation, it is reallocated.
     * @param rtype desired output matrix type or, rather, the depth since the number of channels are the same as the input has; if rtype is negative, the output matrix will have the same type as the input.
     * @param alpha optional scale factor.
     * @param beta optional delta added to the scaled values.
     */
    convertTo(src: CvMat, dst: CvMat, rtype: DataTypes, alpha?: number, beta?: number): void;
}
