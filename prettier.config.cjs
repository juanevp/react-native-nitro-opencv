/** @type {import('prettier').Config} */
module.exports = {
    //endOfLine: "lf",
    semi: true,
    singleQuote: false,
    printWidth: 120,
    tabWidth: 4,
    trailingComma: "es5",
    importOrder: [
        "<THIRD_PARTY_MODULES>",
        "",
        "^types$",
        "^~/(.*)$",
        "^[./]",
    ],
    importOrderSeparation: false,
    importOrderSortSpecifiers: true,
    importOrderBuiltinModulesToTop: true,
    importOrderParserPlugins: ["typescript", "jsx", "decorators-legacy"],
    importOrderMergeDuplicateImports: true,
    importOrderCombineTypeAndValueImports: true,
    plugins: ["@ianvs/prettier-plugin-sort-imports"],
    bracketSpacing: false,
    bracketSameLine: false,
    arrowParens: "avoid",
};
