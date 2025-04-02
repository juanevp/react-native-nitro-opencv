export var ColormapTypes;
(function (ColormapTypes) {
    ColormapTypes[ColormapTypes["COLORMAP_AUTUMN"] = 0] = "COLORMAP_AUTUMN";
    ColormapTypes[ColormapTypes["COLORMAP_BONE"] = 1] = "COLORMAP_BONE";
    ColormapTypes[ColormapTypes["COLORMAP_JET"] = 2] = "COLORMAP_JET";
    ColormapTypes[ColormapTypes["COLORMAP_WINTER"] = 3] = "COLORMAP_WINTER";
    ColormapTypes[ColormapTypes["COLORMAP_RAINBOW"] = 4] = "COLORMAP_RAINBOW";
    ColormapTypes[ColormapTypes["COLORMAP_OCEAN"] = 5] = "COLORMAP_OCEAN";
    ColormapTypes[ColormapTypes["COLORMAP_SUMMER"] = 6] = "COLORMAP_SUMMER";
    ColormapTypes[ColormapTypes["COLORMAP_SPRING"] = 7] = "COLORMAP_SPRING";
    ColormapTypes[ColormapTypes["COLORMAP_COOL"] = 8] = "COLORMAP_COOL";
    ColormapTypes[ColormapTypes["COLORMAP_HSV"] = 9] = "COLORMAP_HSV";
    ColormapTypes[ColormapTypes["COLORMAP_PINK"] = 10] = "COLORMAP_PINK";
    ColormapTypes[ColormapTypes["COLORMAP_HOT"] = 11] = "COLORMAP_HOT";
    ColormapTypes[ColormapTypes["COLORMAP_PARULA"] = 12] = "COLORMAP_PARULA";
    ColormapTypes[ColormapTypes["COLORMAP_MAGMA"] = 13] = "COLORMAP_MAGMA";
    ColormapTypes[ColormapTypes["COLORMAP_INFERNO"] = 14] = "COLORMAP_INFERNO";
    ColormapTypes[ColormapTypes["COLORMAP_PLASMA"] = 15] = "COLORMAP_PLASMA";
    ColormapTypes[ColormapTypes["COLORMAP_VIRIDIS"] = 16] = "COLORMAP_VIRIDIS";
    ColormapTypes[ColormapTypes["COLORMAP_CIVIDIS"] = 17] = "COLORMAP_CIVIDIS";
    ColormapTypes[ColormapTypes["COLORMAP_TWILIGHT"] = 18] = "COLORMAP_TWILIGHT";
    ColormapTypes[ColormapTypes["COLORMAP_TWILIGHT_SHIFTED"] = 19] = "COLORMAP_TWILIGHT_SHIFTED";
    ColormapTypes[ColormapTypes["COLORMAP_TURBO"] = 20] = "COLORMAP_TURBO";
    ColormapTypes[ColormapTypes["COLORMAP_DEEPGREEN"] = 21] = "COLORMAP_DEEPGREEN";
})(ColormapTypes || (ColormapTypes = {}));
export var HersheyFonts;
(function (HersheyFonts) {
    HersheyFonts[HersheyFonts["FONT_HERSHEY_SIMPLEX"] = 0] = "FONT_HERSHEY_SIMPLEX";
    HersheyFonts[HersheyFonts["FONT_HERSHEY_PLAIN"] = 1] = "FONT_HERSHEY_PLAIN";
    HersheyFonts[HersheyFonts["FONT_HERSHEY_DUPLEX"] = 2] = "FONT_HERSHEY_DUPLEX";
    HersheyFonts[HersheyFonts["FONT_HERSHEY_COMPLEX"] = 3] = "FONT_HERSHEY_COMPLEX";
    HersheyFonts[HersheyFonts["FONT_HERSHEY_TRIPLEX"] = 4] = "FONT_HERSHEY_TRIPLEX";
    HersheyFonts[HersheyFonts["FONT_HERSHEY_COMPLEX_SMALL"] = 5] = "FONT_HERSHEY_COMPLEX_SMALL";
    HersheyFonts[HersheyFonts["FONT_HERSHEY_SCRIPT_SIMPLEX"] = 6] = "FONT_HERSHEY_SCRIPT_SIMPLEX";
    HersheyFonts[HersheyFonts["FONT_HERSHEY_SCRIPT_COMPLEX"] = 7] = "FONT_HERSHEY_SCRIPT_COMPLEX";
    HersheyFonts[HersheyFonts["FONT_ITALIC"] = 16] = "FONT_ITALIC";
})(HersheyFonts || (HersheyFonts = {}));
export var LineTypes;
(function (LineTypes) {
    LineTypes[LineTypes["FILLED"] = -1] = "FILLED";
    LineTypes[LineTypes["LINE_4"] = 4] = "LINE_4";
    LineTypes[LineTypes["LINE_8"] = 8] = "LINE_8";
    LineTypes[LineTypes["LINE_AA"] = 16] = "LINE_AA";
})(LineTypes || (LineTypes = {}));
export var MarkerTypes;
(function (MarkerTypes) {
    MarkerTypes[MarkerTypes["MARKER_CROSS"] = 0] = "MARKER_CROSS";
    MarkerTypes[MarkerTypes["MARKER_TILTED_CROSS"] = 1] = "MARKER_TILTED_CROSS";
    MarkerTypes[MarkerTypes["MARKER_STAR"] = 2] = "MARKER_STAR";
    MarkerTypes[MarkerTypes["MARKER_DIAMOND"] = 3] = "MARKER_DIAMOND";
    MarkerTypes[MarkerTypes["MARKER_SQUARE"] = 4] = "MARKER_SQUARE";
    MarkerTypes[MarkerTypes["MARKER_TRIANGLE_UP"] = 5] = "MARKER_TRIANGLE_UP";
    MarkerTypes[MarkerTypes["MARKER_TRIANGLE_DOWN"] = 6] = "MARKER_TRIANGLE_DOWN";
})(MarkerTypes || (MarkerTypes = {}));
export var HoughModes;
(function (HoughModes) {
    HoughModes[HoughModes["HOUGH_STANDARD"] = 0] = "HOUGH_STANDARD";
    HoughModes[HoughModes["HOUGH_PROBABILISTIC"] = 1] = "HOUGH_PROBABILISTIC";
    HoughModes[HoughModes["HOUGH_MULTI_SCALE"] = 2] = "HOUGH_MULTI_SCALE";
    HoughModes[HoughModes["HOUGH_GRADIENT"] = 3] = "HOUGH_GRADIENT";
    HoughModes[HoughModes["HOUGH_GRADIENT_ALT"] = 4] = "HOUGH_GRADIENT_ALT";
})(HoughModes || (HoughModes = {}));
export var LineSegmentDetectorModes;
(function (LineSegmentDetectorModes) {
    LineSegmentDetectorModes[LineSegmentDetectorModes["LSD_REFINE_NONE"] = 0] = "LSD_REFINE_NONE";
    LineSegmentDetectorModes[LineSegmentDetectorModes["LSD_REFINE_STD"] = 1] = "LSD_REFINE_STD";
    LineSegmentDetectorModes[LineSegmentDetectorModes["LSD_REFINE_ADV"] = 2] = "LSD_REFINE_ADV";
})(LineSegmentDetectorModes || (LineSegmentDetectorModes = {}));
export var MorphShapes;
(function (MorphShapes) {
    MorphShapes[MorphShapes["MORPH_RECT"] = 0] = "MORPH_RECT";
    MorphShapes[MorphShapes["MORPH_CROSS"] = 1] = "MORPH_CROSS";
    MorphShapes[MorphShapes["MORPH_ELLIPSE"] = 2] = "MORPH_ELLIPSE";
})(MorphShapes || (MorphShapes = {}));
export var MorphTypes;
(function (MorphTypes) {
    MorphTypes[MorphTypes["MORPH_ERODE"] = 0] = "MORPH_ERODE";
    MorphTypes[MorphTypes["MORPH_DILATE"] = 1] = "MORPH_DILATE";
    MorphTypes[MorphTypes["MORPH_OPEN"] = 2] = "MORPH_OPEN";
    MorphTypes[MorphTypes["MORPH_CLOSE"] = 3] = "MORPH_CLOSE";
    MorphTypes[MorphTypes["MORPH_GRADIENT"] = 4] = "MORPH_GRADIENT";
    MorphTypes[MorphTypes["MORPH_TOPHAT"] = 5] = "MORPH_TOPHAT";
    MorphTypes[MorphTypes["MORPH_BLACKHAT"] = 6] = "MORPH_BLACKHAT";
    MorphTypes[MorphTypes["MORPH_HITMISS"] = 7] = "MORPH_HITMISS";
})(MorphTypes || (MorphTypes = {}));
export var SpecialFilter;
(function (SpecialFilter) {
    SpecialFilter["FILTER_SCHARR"] = "FILTER_SCHARR";
})(SpecialFilter || (SpecialFilter = {}));
export var AdaptiveThresholdTypes;
(function (AdaptiveThresholdTypes) {
    AdaptiveThresholdTypes[AdaptiveThresholdTypes["ADAPTIVE_THRESH_MEAN_C"] = 0] = "ADAPTIVE_THRESH_MEAN_C";
    AdaptiveThresholdTypes[AdaptiveThresholdTypes["ADAPTIVE_THRESH_GAUSSIAN_C"] = 1] = "ADAPTIVE_THRESH_GAUSSIAN_C";
})(AdaptiveThresholdTypes || (AdaptiveThresholdTypes = {}));
export var DistanceTransformLabelTypes;
(function (DistanceTransformLabelTypes) {
    DistanceTransformLabelTypes[DistanceTransformLabelTypes["DIST_LABEL_CCOMP"] = 0] = "DIST_LABEL_CCOMP";
    DistanceTransformLabelTypes[DistanceTransformLabelTypes["DIST_LABEL_PIXEL"] = 1] = "DIST_LABEL_PIXEL";
})(DistanceTransformLabelTypes || (DistanceTransformLabelTypes = {}));
export var DistanceTransformMasks;
(function (DistanceTransformMasks) {
    DistanceTransformMasks[DistanceTransformMasks["DIST_MASK_3"] = 3] = "DIST_MASK_3";
    DistanceTransformMasks[DistanceTransformMasks["DIST_MASK_5"] = 5] = "DIST_MASK_5";
    DistanceTransformMasks[DistanceTransformMasks["DIST_MASK_PRECISE"] = 0] = "DIST_MASK_PRECISE";
})(DistanceTransformMasks || (DistanceTransformMasks = {}));
export var DistanceTypes;
(function (DistanceTypes) {
    DistanceTypes[DistanceTypes["DIST_USER"] = -1] = "DIST_USER";
    DistanceTypes[DistanceTypes["DIST_L1"] = 1] = "DIST_L1";
    DistanceTypes[DistanceTypes["DIST_L2"] = 2] = "DIST_L2";
    DistanceTypes[DistanceTypes["DIST_C"] = 3] = "DIST_C";
    DistanceTypes[DistanceTypes["DIST_L12"] = 4] = "DIST_L12";
    DistanceTypes[DistanceTypes["DIST_FAIR"] = 5] = "DIST_FAIR";
    DistanceTypes[DistanceTypes["DIST_WELSCH"] = 6] = "DIST_WELSCH";
    DistanceTypes[DistanceTypes["DIST_HUBER"] = 7] = "DIST_HUBER";
})(DistanceTypes || (DistanceTypes = {}));
export var FloodFillFlags;
(function (FloodFillFlags) {
    FloodFillFlags[FloodFillFlags["FLOODFILL_FIXED_RANGE"] = 65536] = "FLOODFILL_FIXED_RANGE";
    FloodFillFlags[FloodFillFlags["FLOODFILL_MASK_ONLY"] = 131072] = "FLOODFILL_MASK_ONLY";
})(FloodFillFlags || (FloodFillFlags = {}));
export var GrabCutClasses;
(function (GrabCutClasses) {
    GrabCutClasses[GrabCutClasses["GC_BGD"] = 0] = "GC_BGD";
    GrabCutClasses[GrabCutClasses["GC_FGD"] = 1] = "GC_FGD";
    GrabCutClasses[GrabCutClasses["GC_PR_BGD"] = 2] = "GC_PR_BGD";
    GrabCutClasses[GrabCutClasses["GC_PR_FGD"] = 3] = "GC_PR_FGD";
})(GrabCutClasses || (GrabCutClasses = {}));
export var GrabCutModes;
(function (GrabCutModes) {
    GrabCutModes[GrabCutModes["GC_INIT_WITH_RECT"] = 0] = "GC_INIT_WITH_RECT";
    GrabCutModes[GrabCutModes["GC_INIT_WITH_MASK"] = 1] = "GC_INIT_WITH_MASK";
    GrabCutModes[GrabCutModes["GC_EVAL"] = 2] = "GC_EVAL";
    GrabCutModes[GrabCutModes["GC_EVAL_FREEZE_MODEL"] = 3] = "GC_EVAL_FREEZE_MODEL";
})(GrabCutModes || (GrabCutModes = {}));
export var ThresholdTypes;
(function (ThresholdTypes) {
    ThresholdTypes[ThresholdTypes["THRESH_BINARY"] = 0] = "THRESH_BINARY";
    ThresholdTypes[ThresholdTypes["THRESH_BINARY_INV"] = 1] = "THRESH_BINARY_INV";
    ThresholdTypes[ThresholdTypes["THRESH_TRUNC"] = 2] = "THRESH_TRUNC";
    ThresholdTypes[ThresholdTypes["THRESH_TOZERO"] = 3] = "THRESH_TOZERO";
    ThresholdTypes[ThresholdTypes["THRESH_TOZERO_INV"] = 4] = "THRESH_TOZERO_INV";
    ThresholdTypes[ThresholdTypes["THRESH_MASK"] = 7] = "THRESH_MASK";
    ThresholdTypes[ThresholdTypes["THRESH_OTSU"] = 8] = "THRESH_OTSU";
    ThresholdTypes[ThresholdTypes["THRESH_TRIANGLE"] = 16] = "THRESH_TRIANGLE";
})(ThresholdTypes || (ThresholdTypes = {}));
export var TemplateMatchModes;
(function (TemplateMatchModes) {
    TemplateMatchModes[TemplateMatchModes["TM_SQDIFF"] = 0] = "TM_SQDIFF";
    TemplateMatchModes[TemplateMatchModes["TM_SQDIFF_NORMED"] = 1] = "TM_SQDIFF_NORMED";
    TemplateMatchModes[TemplateMatchModes["TM_CCORR"] = 2] = "TM_CCORR";
    TemplateMatchModes[TemplateMatchModes["TM_CCORR_NORMED"] = 3] = "TM_CCORR_NORMED";
    TemplateMatchModes[TemplateMatchModes["TM_CCOEFF"] = 4] = "TM_CCOEFF";
    TemplateMatchModes[TemplateMatchModes["TM_CCOEFF_NORMED"] = 5] = "TM_CCOEFF_NORMED";
})(TemplateMatchModes || (TemplateMatchModes = {}));
export var ConnectedComponentsAlgorithmsTypes;
(function (ConnectedComponentsAlgorithmsTypes) {
    ConnectedComponentsAlgorithmsTypes[ConnectedComponentsAlgorithmsTypes["CCL_DEFAULT"] = -1] = "CCL_DEFAULT";
    ConnectedComponentsAlgorithmsTypes[ConnectedComponentsAlgorithmsTypes["CCL_WU"] = 0] = "CCL_WU";
    ConnectedComponentsAlgorithmsTypes[ConnectedComponentsAlgorithmsTypes["CCL_GRANA"] = 1] = "CCL_GRANA";
    ConnectedComponentsAlgorithmsTypes[ConnectedComponentsAlgorithmsTypes["CCL_BOLELLI"] = 2] = "CCL_BOLELLI";
    ConnectedComponentsAlgorithmsTypes[ConnectedComponentsAlgorithmsTypes["CCL_SAUF"] = 3] = "CCL_SAUF";
    ConnectedComponentsAlgorithmsTypes[ConnectedComponentsAlgorithmsTypes["CCL_BBDT"] = 4] = "CCL_BBDT";
    ConnectedComponentsAlgorithmsTypes[ConnectedComponentsAlgorithmsTypes["CCL_SPAGHETTI"] = 5] = "CCL_SPAGHETTI";
})(ConnectedComponentsAlgorithmsTypes || (ConnectedComponentsAlgorithmsTypes = {}));
export var ConnectedComponentsTypes;
(function (ConnectedComponentsTypes) {
    ConnectedComponentsTypes[ConnectedComponentsTypes["CC_STAT_LEFT"] = 0] = "CC_STAT_LEFT";
    ConnectedComponentsTypes[ConnectedComponentsTypes["CC_STAT_TOP"] = 1] = "CC_STAT_TOP";
    ConnectedComponentsTypes[ConnectedComponentsTypes["CC_STAT_WIDTH"] = 2] = "CC_STAT_WIDTH";
    ConnectedComponentsTypes[ConnectedComponentsTypes["CC_STAT_HEIGHT"] = 3] = "CC_STAT_HEIGHT";
    ConnectedComponentsTypes[ConnectedComponentsTypes["CC_STAT_AREA"] = 4] = "CC_STAT_AREA";
})(ConnectedComponentsTypes || (ConnectedComponentsTypes = {}));
export var ContourApproximationModes;
(function (ContourApproximationModes) {
    ContourApproximationModes[ContourApproximationModes["CHAIN_APPROX_NONE"] = 1] = "CHAIN_APPROX_NONE";
    ContourApproximationModes[ContourApproximationModes["CHAIN_APPROX_SIMPLE"] = 2] = "CHAIN_APPROX_SIMPLE";
    ContourApproximationModes[ContourApproximationModes["CHAIN_APPROX_TC89_L1"] = 3] = "CHAIN_APPROX_TC89_L1";
    ContourApproximationModes[ContourApproximationModes["CHAIN_APPROX_TC89_KCOS"] = 4] = "CHAIN_APPROX_TC89_KCOS";
})(ContourApproximationModes || (ContourApproximationModes = {}));
export var RectanglesIntersectTypes;
(function (RectanglesIntersectTypes) {
    RectanglesIntersectTypes[RectanglesIntersectTypes["INTERSECT_NONE"] = 0] = "INTERSECT_NONE";
    RectanglesIntersectTypes[RectanglesIntersectTypes["INTERSECT_PARTIAL"] = 1] = "INTERSECT_PARTIAL";
    RectanglesIntersectTypes[RectanglesIntersectTypes["INTERSECT_FULL"] = 2] = "INTERSECT_FULL";
})(RectanglesIntersectTypes || (RectanglesIntersectTypes = {}));
export var RetrievalModes;
(function (RetrievalModes) {
    RetrievalModes[RetrievalModes["RETR_EXTERNAL"] = 0] = "RETR_EXTERNAL";
    RetrievalModes[RetrievalModes["RETR_LIST"] = 1] = "RETR_LIST";
    RetrievalModes[RetrievalModes["RETR_CCOMP"] = 2] = "RETR_CCOMP";
    RetrievalModes[RetrievalModes["RETR_TREE"] = 3] = "RETR_TREE";
    RetrievalModes[RetrievalModes["RETR_FLOODFILL"] = 4] = "RETR_FLOODFILL";
})(RetrievalModes || (RetrievalModes = {}));
export var ShapeMatchModes;
(function (ShapeMatchModes) {
    ShapeMatchModes[ShapeMatchModes["CONTOURS_MATCH_I1"] = 1] = "CONTOURS_MATCH_I1";
    ShapeMatchModes[ShapeMatchModes["CONTOURS_MATCH_I2"] = 2] = "CONTOURS_MATCH_I2";
    ShapeMatchModes[ShapeMatchModes["CONTOURS_MATCH_I3"] = 3] = "CONTOURS_MATCH_I3";
})(ShapeMatchModes || (ShapeMatchModes = {}));
export var OpticalFlowFlags;
(function (OpticalFlowFlags) {
    OpticalFlowFlags[OpticalFlowFlags["OPTFLOW_USE_INITIAL_FLOW"] = 4] = "OPTFLOW_USE_INITIAL_FLOW";
    OpticalFlowFlags[OpticalFlowFlags["OPTFLOW_LK_GET_MIN_EIGENVALS"] = 8] = "OPTFLOW_LK_GET_MIN_EIGENVALS";
    OpticalFlowFlags[OpticalFlowFlags["OPTFLOW_FARNEBACK_GAUSSIAN"] = 256] = "OPTFLOW_FARNEBACK_GAUSSIAN";
})(OpticalFlowFlags || (OpticalFlowFlags = {}));
