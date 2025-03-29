import reactPlugin from "@eslint-react/eslint-plugin";
import eslint from "@eslint/js";
import hooksPlugin from "eslint-plugin-react-hooks";
import globals from "globals";
import tseslint from "typescript-eslint";

export default tseslint.config(
    eslint.configs.recommended,
    ...tseslint.configs.recommendedTypeChecked,
    {
        files: ["**/*.js", "**/*.cjs", "**/*.mjs"],
        ...tseslint.configs.disableTypeChecked,
    },
    reactPlugin.configs["recommended-type-checked"],
    {
        plugins: {
            "react-hooks": hooksPlugin,
        },
        rules: {
            "react/react-in-jsx-scope": "off",
            ...hooksPlugin.configs.recommended.rules,
        },
        ignores: ["*.test.tsx"],
    },
    {
        ignores: ["dist/", "node_modules/", "lib/", "eslint.config.ts", "prettier.config.cjs", "scripts/"],
    },
    {
        files: ["**/*.ts", "**/*.tsx"],
        languageOptions: {
            ecmaVersion: 2025,
            sourceType: "module",
            globals: {
                ...globals.node,
            },
            parserOptions: {
                projectService: true,
                tsconfigRootDir: import.meta.dirname,
            },
        },
        plugins: {},
        rules: {
            "@typescript-eslint/no-explicit-any": "off",
            "@typescript-eslint/no-unsafe-assignment": "off",
            "@typescript-eslint/no-unsafe-return": "off",
            "@typescript-eslint/no-unsafe-member-access": "off",
            "@typescript-eslint/no-unsafe-argument": "off",
            "@typescript-eslint/unbound-method": "off",
            "@typescript-eslint/no-misused-promises": [
                "off",
                {
                    checksVoidReturn: false,
                },
            ],
        },
    }
);
