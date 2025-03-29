"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.InterpolationFlags = void 0;
var InterpolationFlags;
(function (InterpolationFlags) {
    InterpolationFlags[InterpolationFlags["INTER_NEAREST"] = 0] = "INTER_NEAREST";
    InterpolationFlags[InterpolationFlags["INTER_LINEAR"] = 1] = "INTER_LINEAR";
    InterpolationFlags[InterpolationFlags["INTER_CUBIC"] = 2] = "INTER_CUBIC";
    InterpolationFlags[InterpolationFlags["INTER_AREA"] = 3] = "INTER_AREA";
    InterpolationFlags[InterpolationFlags["INTER_LANCZOS4"] = 4] = "INTER_LANCZOS4";
    InterpolationFlags[InterpolationFlags["INTER_LINEAR_EXACT"] = 5] = "INTER_LINEAR_EXACT";
    InterpolationFlags[InterpolationFlags["INTER_NEAREST_EXACT"] = 6] = "INTER_NEAREST_EXACT";
    InterpolationFlags[InterpolationFlags["INTER_MAX"] = 7] = "INTER_MAX";
    InterpolationFlags[InterpolationFlags["WARP_FILL_OUTLIERS"] = 8] = "WARP_FILL_OUTLIERS";
    InterpolationFlags[InterpolationFlags["WARP_INVERSE_MAP"] = 16] = "WARP_INVERSE_MAP";
    InterpolationFlags[InterpolationFlags["WARP_RELATIVE_MAP"] = 32] = "WARP_RELATIVE_MAP";
})(InterpolationFlags || (exports.InterpolationFlags = InterpolationFlags = {}));
