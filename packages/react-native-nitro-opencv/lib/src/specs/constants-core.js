export var CovarFlags;
(function (CovarFlags) {
    CovarFlags[CovarFlags["COVAR_SCRAMBLED"] = 0] = "COVAR_SCRAMBLED";
    CovarFlags[CovarFlags["COVAR_NORMAL"] = 1] = "COVAR_NORMAL";
    CovarFlags[CovarFlags["COVAR_USE_AVG"] = 2] = "COVAR_USE_AVG";
    CovarFlags[CovarFlags["COVAR_SCALE"] = 4] = "COVAR_SCALE";
    CovarFlags[CovarFlags["COVAR_ROWS"] = 8] = "COVAR_ROWS";
    CovarFlags[CovarFlags["COVAR_COLS"] = 16] = "COVAR_COLS";
})(CovarFlags || (CovarFlags = {}));
export var QuatAssumeType;
(function (QuatAssumeType) {
    QuatAssumeType["QUAT_ASSUME_NOT_UNIT"] = "QUAT_ASSUME_NOT_UNIT";
    QuatAssumeType["QUAT_ASSUME_UNIT"] = "QUAT_ASSUME_UNIT";
})(QuatAssumeType || (QuatAssumeType = {}));
export var DecompTypes;
(function (DecompTypes) {
    DecompTypes[DecompTypes["DECOMP_LU"] = 0] = "DECOMP_LU";
    DecompTypes[DecompTypes["DECOMP_SVD"] = 1] = "DECOMP_SVD";
    DecompTypes[DecompTypes["DECOMP_EIG"] = 2] = "DECOMP_EIG";
    DecompTypes[DecompTypes["DECOMP_CHOLESKY"] = 3] = "DECOMP_CHOLESKY";
    DecompTypes[DecompTypes["DECOMP_QR"] = 4] = "DECOMP_QR";
    DecompTypes[DecompTypes["DECOMP_NORMAL"] = 16] = "DECOMP_NORMAL";
})(DecompTypes || (DecompTypes = {}));
export var BorderTypes;
(function (BorderTypes) {
    BorderTypes[BorderTypes["BORDER_CONSTANT"] = 0] = "BORDER_CONSTANT";
    BorderTypes[BorderTypes["BORDER_REPLICATE"] = 1] = "BORDER_REPLICATE";
    BorderTypes[BorderTypes["BORDER_REFLECT"] = 2] = "BORDER_REFLECT";
    BorderTypes[BorderTypes["BORDER_WRAP"] = 3] = "BORDER_WRAP";
    BorderTypes[BorderTypes["BORDER_REFLECT_101"] = 4] = "BORDER_REFLECT_101";
    BorderTypes[BorderTypes["BORDER_TRANSPARENT"] = 5] = "BORDER_TRANSPARENT";
    BorderTypes[BorderTypes["BORDER_REFLECT101"] = 4] = "BORDER_REFLECT101";
    BorderTypes[BorderTypes["BORDER_DEFAULT"] = 4] = "BORDER_DEFAULT";
    BorderTypes[BorderTypes["BORDER_ISOLATED"] = 16] = "BORDER_ISOLATED";
})(BorderTypes || (BorderTypes = {}));
export var CmpTypes;
(function (CmpTypes) {
    CmpTypes[CmpTypes["CMP_EQ"] = 0] = "CMP_EQ";
    CmpTypes[CmpTypes["CMP_GT"] = 1] = "CMP_GT";
    CmpTypes[CmpTypes["CMP_GE"] = 2] = "CMP_GE";
    CmpTypes[CmpTypes["CMP_LT"] = 3] = "CMP_LT";
    CmpTypes[CmpTypes["CMP_LE"] = 4] = "CMP_LE";
    CmpTypes[CmpTypes["CMP_NE"] = 5] = "CMP_NE";
})(CmpTypes || (CmpTypes = {}));
export var DftFlags;
(function (DftFlags) {
    DftFlags[DftFlags["DFT_INVERSE"] = 1] = "DFT_INVERSE";
    DftFlags[DftFlags["DFT_SCALE"] = 2] = "DFT_SCALE";
    DftFlags[DftFlags["DFT_ROWS"] = 4] = "DFT_ROWS";
    DftFlags[DftFlags["DFT_COMPLEX_OUTPUT"] = 16] = "DFT_COMPLEX_OUTPUT";
    DftFlags[DftFlags["DFT_REAL_OUTPUT"] = 32] = "DFT_REAL_OUTPUT";
    DftFlags[DftFlags["DFT_COMPLEX_INPUT"] = 64] = "DFT_COMPLEX_INPUT";
    DftFlags[DftFlags["DCT_INVERSE"] = 1] = "DCT_INVERSE";
    DftFlags[DftFlags["DCT_ROWS"] = 4] = "DCT_ROWS";
})(DftFlags || (DftFlags = {}));
export var GemmFlags;
(function (GemmFlags) {
    GemmFlags[GemmFlags["GEMM_1_T"] = 1] = "GEMM_1_T";
    GemmFlags[GemmFlags["GEMM_2_T"] = 2] = "GEMM_2_T";
    GemmFlags[GemmFlags["GEMM_3_T"] = 4] = "GEMM_3_T";
})(GemmFlags || (GemmFlags = {}));
export var NormTypes;
(function (NormTypes) {
    NormTypes[NormTypes["NORM_INF"] = 1] = "NORM_INF";
    NormTypes[NormTypes["NORM_L1"] = 2] = "NORM_L1";
    NormTypes[NormTypes["NORM_L2"] = 4] = "NORM_L2";
    NormTypes[NormTypes["NORM_L2SQR"] = 5] = "NORM_L2SQR";
    NormTypes[NormTypes["NORM_HAMMING"] = 6] = "NORM_HAMMING";
    NormTypes[NormTypes["NORM_HAMMING2"] = 7] = "NORM_HAMMING2";
    NormTypes[NormTypes["NORM_TYPE_MASK"] = 7] = "NORM_TYPE_MASK";
    NormTypes[NormTypes["NORM_RELATIVE"] = 8] = "NORM_RELATIVE";
    NormTypes[NormTypes["NORM_MINMAX"] = 32] = "NORM_MINMAX";
})(NormTypes || (NormTypes = {}));
export var ReduceTypes;
(function (ReduceTypes) {
    ReduceTypes[ReduceTypes["REDUCE_SUM"] = 0] = "REDUCE_SUM";
    ReduceTypes[ReduceTypes["REDUCE_AVG"] = 1] = "REDUCE_AVG";
    ReduceTypes[ReduceTypes["REDUCE_MAX"] = 2] = "REDUCE_MAX";
    ReduceTypes[ReduceTypes["REDUCE_MIN"] = 3] = "REDUCE_MIN";
})(ReduceTypes || (ReduceTypes = {}));
export var RotateFlags;
(function (RotateFlags) {
    RotateFlags[RotateFlags["ROTATE_90_CLOCKWISE"] = 0] = "ROTATE_90_CLOCKWISE";
    RotateFlags[RotateFlags["ROTATE_180"] = 1] = "ROTATE_180";
    RotateFlags[RotateFlags["ROTATE_90_COUNTERCLOCKWISE"] = 2] = "ROTATE_90_COUNTERCLOCKWISE";
})(RotateFlags || (RotateFlags = {}));
export var SortFlags;
(function (SortFlags) {
    SortFlags[SortFlags["SORT_EVERY_ROW"] = 0] = "SORT_EVERY_ROW";
    SortFlags[SortFlags["SORT_EVERY_COLUMN"] = 1] = "SORT_EVERY_COLUMN";
    SortFlags[SortFlags["SORT_ASCENDING"] = 0] = "SORT_ASCENDING";
    SortFlags[SortFlags["SORT_DESCENDING"] = 16] = "SORT_DESCENDING";
})(SortFlags || (SortFlags = {}));
export var TermCriteriaType;
(function (TermCriteriaType) {
    TermCriteriaType[TermCriteriaType["COUNT"] = 1] = "COUNT";
    TermCriteriaType[TermCriteriaType["MAX_ITER"] = 1] = "MAX_ITER";
    TermCriteriaType[TermCriteriaType["EPS"] = 2] = "EPS";
})(TermCriteriaType || (TermCriteriaType = {}));
