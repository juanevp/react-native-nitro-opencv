export declare enum CovarFlags {
    COVAR_SCRAMBLED = 0,
    COVAR_NORMAL = 1,
    COVAR_USE_AVG = 2,
    COVAR_SCALE = 4,
    COVAR_ROWS = 8,
    COVAR_COLS = 16
}
export declare enum QuatAssumeType {
    QUAT_ASSUME_NOT_UNIT = "QUAT_ASSUME_NOT_UNIT",
    QUAT_ASSUME_UNIT = "QUAT_ASSUME_UNIT"
}
export declare enum DecompTypes {
    DECOMP_LU = 0,
    DECOMP_SVD = 1,
    DECOMP_EIG = 2,
    DECOMP_CHOLESKY = 3,
    DECOMP_QR = 4,
    DECOMP_NORMAL = 16
}
export declare enum BorderTypes {
    BORDER_CONSTANT = 0,
    BORDER_REPLICATE = 1,
    BORDER_REFLECT = 2,
    BORDER_WRAP = 3,
    BORDER_REFLECT_101 = 4,
    BORDER_TRANSPARENT = 5,
    BORDER_REFLECT101 = 4,
    BORDER_DEFAULT = 4,
    BORDER_ISOLATED = 16
}
export declare enum CmpTypes {
    CMP_EQ = 0,
    CMP_GT = 1,
    CMP_GE = 2,
    CMP_LT = 3,
    CMP_LE = 4,
    CMP_NE = 5
}
export declare enum DftFlags {
    DFT_INVERSE = 1,
    DFT_SCALE = 2,
    DFT_ROWS = 4,
    DFT_COMPLEX_OUTPUT = 16,
    DFT_REAL_OUTPUT = 32,
    DFT_COMPLEX_INPUT = 64,
    DCT_INVERSE = 1,
    DCT_ROWS = 4
}
export declare enum GemmFlags {
    GEMM_1_T = 1,
    GEMM_2_T = 2,
    GEMM_3_T = 4
}
export declare enum NormTypes {
    NORM_INF = 1,
    NORM_L1 = 2,
    NORM_L2 = 4,
    NORM_L2SQR = 5,
    NORM_HAMMING = 6,
    NORM_HAMMING2 = 7,
    NORM_TYPE_MASK = 7,
    NORM_RELATIVE = 8,
    NORM_MINMAX = 32
}
export declare enum ReduceTypes {
    REDUCE_SUM = 0,
    REDUCE_AVG = 1,
    REDUCE_MAX = 2,
    REDUCE_MIN = 3
}
export declare enum RotateFlags {
    ROTATE_90_CLOCKWISE = 0,
    ROTATE_180 = 1,
    ROTATE_90_COUNTERCLOCKWISE = 2
}
export declare enum SortFlags {
    SORT_EVERY_ROW = 0,
    SORT_EVERY_COLUMN = 1,
    SORT_ASCENDING = 0,
    SORT_DESCENDING = 16
}
export declare enum TermCriteriaType {
    COUNT = 1,
    MAX_ITER = 1,
    EPS = 2
}
