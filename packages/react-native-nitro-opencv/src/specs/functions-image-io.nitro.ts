import {type HybridObject} from "react-native-nitro-modules";

import type {ImreadModes, ImwriteFlags} from "./constants-image-io";
import type {MatVector} from "./mat-vector.nitro";
import type {CvMat} from "./mat.nitro";
import type {CvRange} from "./range.nitro";

export interface ImageIo extends HybridObject<{ios: "c++"; android: "c++"}> {
    /**
     * Checks if the specified image file can be decoded by OpenCV.
     *
     * The function haveImageReader checks if OpenCV is capable of reading the specified file.
     * This can be useful for verifying support for a given image format before attempting to load an image.
     *
     * Note
     * The function checks the availability of image codecs that are either built into OpenCV or dynamically loaded.
     * It does not check for the actual existence of the file but rather the ability to read the specified file type.
     * If the file cannot be opened or the format is unsupported, the function will return false.
     *
     * @param filename The name of the file to be checked.
     */
    haveImageReader(filename: string): boolean;

    /**
     * Checks if the specified image file or specified file extension can be encoded by OpenCV.
     *
     * The function haveImageWriter checks if OpenCV is capable of writing images with the specified file extension.
     * This can be useful for verifying support for a given image format before attempting to save an image.
     *
     * Note
     * The function checks the availability of image codecs that are either built into OpenCV or dynamically loaded.
     * It does not check for the actual existence of the file but rather the ability to write files of the given type.
     *
     * @param filename 	The name of the file or the file extension (e.g., ".jpg", ".png"). It is recommended to provide the file extension rather than the full file name.
     */
    haveImageWriter(filename: string): boolean;

    /**
     * Returns the number of images inside the given file.
     *
     * The function imcount returns the number of pages in a multi-page image (e.g. TIFF), the number of frames in an animation (e.g. AVIF), and 1 otherwise.
     * If the image cannot be decoded, 0 is returned.
     *
     * @param filename Name of file to be loaded.
     * @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.
     */
    imcount(filename: string, flags?: ImreadModes): number;

    /**
     * Reads an image from a buffer in memory.
     *
     * The function imdecode reads an image from the specified buffer in the memory.
     * If the buffer is too short or contains invalid data, the function returns an empty matrix ( Mat::data==NULL ).
     *
     * See cv::imread for the list of supported formats and flags description.
     *
     * @param buf Input array or vector of bytes.
     * @param flags The same flags as in cv::imread, see cv::ImreadModes.
     * @param dst The optional output placeholder for the decoded matrix. It can save the image reallocations when the function is called repeatedly for images of the same size. In case of decoder failure the function returns empty cv::Mat object, but does not release user-provided dst buffer.
     */
    imdecode(buf: CvMat, flags: ImreadModes, dst?: CvMat): CvMat;

    /**
     * Reads a multi-page image from a buffer in memory.
     *
     * The function imdecodemulti reads a multi-page image from the specified buffer in the memory.
     * If the buffer is too short or contains invalid data, the function returns false.
     *
     * See cv::imreadmulti for the list of supported formats and flags description.
     *
     * Note
     * In the case of color images, the decoded images will have the channels stored in B G R order.
     *
     * @param buf Input array or vector of bytes.
     * @param flags The same flags as in cv::imread, see cv::ImreadModes.
     * @param mats A vector of Mat objects holding each page, if more than one.
     * @param range A continuous selection of pages.
     */
    imdecodemulti(buf: CvMat, flags: ImreadModes, mats: MatVector, range?: CvRange): boolean;

    /**
     * Encodes an image into a memory buffer.
     *
     * The function imencode compresses the image and stores it in the memory buffer that is resized to fit the result.
     * See cv::imwrite for the list of supported formats and flags description.
     *
     * @param ext File extension that defines the output format. Must include a leading period.
     * @param img Image to be compressed.
     * @param buf Output buffer resized to fit the compressed image.
     * @param params Format-specific parameters. See cv::imwrite and cv::ImwriteFlags.
     */
    imencode(ext: string, img: CvMat, ...params: [ImwriteFlags, number][]): ArrayBuffer | undefined;

    /**
     * Encodes array of images into a memory buffer.
     * The function is analog to cv::imencode for in-memory multi-page image compression. See cv::imwrite for the list of supported formats and flags description.
     *
     * @param ext File extension that defines the output format. Must include a leading period.
     * @param imgs Vector of images to be written.
     * @param buf Output buffer resized to fit the compressed data.
     * @param params Format-specific parameters. See cv::imwrite and cv::ImwriteFlags.
     */
    imencodemulti(ext: string, imgs: MatVector, ...params: [ImwriteFlags, number][]): ArrayBuffer | undefined;

    /**
     * Loads an image from a file.
     *
     * The imread function loads an image from the specified file and returns OpenCV matrix.
     * If the image cannot be read (because of a missing file, improper permissions, or unsupported/invalid format), the function returns an empty matrix.
     *
     * Currently, the following file formats are supported:
     *
     * Windows bitmaps - *.bmp, *.dib (always supported)
     *
     * GIF files - *.gif (always supported)
     *
     * JPEG files - *.jpeg, *.jpg, *.jpe (see the Note section)
     *
     * JPEG 2000 files - *.jp2 (see the Note section)
     *
     * Portable Network Graphics - *.png (see the Note section)
     *
     * WebP - *.webp (see the Note section)
     *
     * AVIF - *.avif (see the Note section)
     *
     * Portable image format - *.pbm, *.pgm, *.ppm, *.pxm, *.pnm (always supported)
     *
     * PFM files - *.pfm (see the Note section)
     *
     * Sun rasters - *.sr, *.ras (always supported)
     *
     * TIFF files - *.tiff, *.tif (see the Note section)
     *
     * OpenEXR Image files - *.exr (see the Note section)
     *
     * Radiance HDR - *.hdr, *.pic (always supported)
     *
     * Raster and Vector geospatial data supported by GDAL (see the Note section)
     *
     * Note
     *
     * -The function determines the type of an image by its content, not by the file extension.
     *
     * -In the case of color images, the decoded images will have the channels stored in B G R order.
     *
     * -When using IMREAD_GRAYSCALE, the codec's internal grayscale conversion will be used, if available. Results may differ from the output of cvtColor().
     *
     * -On Microsoft Windows* and Mac OS*, the codecs shipped with OpenCV (libjpeg, libpng, libtiff, and libjasper) are used by default.
     * So, OpenCV can always read JPEGs, PNGs, and TIFFs. On Mac OS, there is also an option to use native Mac OS image readers.
     * However, beware that currently these native image loaders give images with different pixel values because of the color management embedded into Mac OS.
     *
     * -On Linux*, BSD flavors, and other Unix-like open-source operating systems, OpenCV looks for codecs supplied with the OS.
     * Ensure the relevant packages are installed (including development files, such as "libjpeg-dev" in Debian* and Ubuntu*) to get codec support, or turn on the OPENCV_BUILD_3RDPARTY_LIBS flag in CMake.
     *
     * -If the WITH_GDAL flag is set to true in CMake and IMREAD_LOAD_GDAL is used to load the image, the GDAL driver will be used to decode the image, supporting Raster and Vector formats.
     *
     * -If EXIF information is embedded in the image file, the EXIF orientation will be taken into account, and thus the image will be rotated accordingly unless the flags IMREAD_IGNORE_ORIENTATION or IMREAD_UNCHANGED are passed.
     *
     * -Use the IMREAD_UNCHANGED flag to preserve the floating-point values from PFM images.
     *
     * -By default, the number of pixels must be less than 2^30. This limit can be changed by setting the environment variable OPENCV_IO_MAX_IMAGE_PIXELS. See OpenCV environment variables reference.
     *
     * @param filename Name of the file to be loaded.
     * @param flags Flag that can take values of cv::ImreadModes.
     */
    imread(filename: string, flags?: ImreadModes, dst?: CvMat): CvMat;

    /**
     * Loads a multi-page image from a file.
     *
     * The function imreadmulti loads a multi-page image from the specified file into a vector of Mat objects.
     *
     * @param filename Name of file to be loaded.
     * @param mats A vector of Mat objects holding each page.
     * @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.
     */
    imreadmulti(filename: string, mats: MatVector, flags?: ImreadModes): boolean;

    /**
     * Saves an image to a specified file.
     *
     * The function imwrite saves the image to the specified file. The image format is chosen based on the filename extension (see cv::imread for the list of extensions). In general, only 8-bit unsigned (CV_8U) single-channel or 3-channel (with 'BGR' channel order) images can be saved using this function, with these exceptions:
     *
     * With OpenEXR encoder, only 32-bit float (CV_32F) images can be saved.
     * -8-bit unsigned (CV_8U) images are not supported.
     *
     * With Radiance HDR encoder, non 64-bit float (CV_64F) images can be saved.
     * -All images will be converted to 32-bit float (CV_32F).
     *
     * With JPEG 2000 encoder, 8-bit unsigned (CV_8U) and 16-bit unsigned (CV_16U) images can be saved.
     *
     * With JPEG XL encoder, 8-bit unsigned (CV_8U), 16-bit unsigned (CV_16U) and 32-bit float(CV_32F) images can be saved.
     * -JPEG XL images with an alpha channel can be saved using this function. To do this, create 8-bit (or 16-bit, 32-bit float) 4-channel image BGRA, where the alpha channel goes last. Fully transparent pixels should have alpha set to 0, fully opaque pixels should have alpha set to 255/65535/1.0.
     *
     * With PAM encoder, 8-bit unsigned (CV_8U) and 16-bit unsigned (CV_16U) images can be saved.
     *
     * With PNG encoder, 8-bit unsigned (CV_8U) and 16-bit unsigned (CV_16U) images can be saved.
     * -PNG images with an alpha channel can be saved using this function. To do this, create 8-bit (or 16-bit) 4-channel image BGRA, where the alpha channel goes last. Fully transparent pixels should have alpha set to 0, fully opaque pixels should have alpha set to 255/65535 (see the code sample below).
     *
     * With PGM/PPM encoder, 8-bit unsigned (CV_8U) and 16-bit unsigned (CV_16U) images can be saved.
     *
     * With TIFF encoder, 8-bit unsigned (CV_8U), 8-bit signed (CV_8S), 16-bit unsigned (CV_16U), 16-bit signed (CV_16S), 32-bit signed (CV_32S), 32-bit float (CV_32F) and 64-bit float (CV_64F) images can be saved.
     * -Multiple images (vector of Mat) can be saved in TIFF format (see the code sample below).
     * -32-bit float 3-channel (CV_32FC3) TIFF images will be saved using the LogLuv high dynamic range encoding (4 bytes per pixel)
     *
     * If the image format is not supported, the image will be converted to 8-bit unsigned (CV_8U) and saved that way.
     *
     * If the format, depth or channel order is different, use Mat::convertTo and cv::cvtColor to convert it before saving. Or, use the universal FileStorage I/O functions to save the image to XML or YAML format.
     *
     * @param filename Name of the file.
     * @param img 	(Mat or vector of Mat) Image or Images to be saved.
     * @param params Format-specific parameters encoded as pairs (paramId_1, paramValue_1, paramId_2, paramValue_2, ... .) see cv::ImwriteFlags
     */
    imwrite(filename: string, img: CvMat, ...params: [ImwriteFlags, number][]): boolean;

    imwritemulti(filename: string, img: MatVector, ...params: [ImwriteFlags, number][]): boolean;
}
