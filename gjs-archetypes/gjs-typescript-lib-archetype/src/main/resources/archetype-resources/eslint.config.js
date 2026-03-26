import js from "@eslint/js";
import tseslint from "typescript-eslint";
import globals from "globals";

export default [

  // Ignorados globales
  {
    ignores: [
      "node_modules/**",
      "dist/**",
      "build/**",
      "target/**"
    ]
  },

  // Base JS recommended
  js.configs.recommended,

  // TypeScript recommended
  ...tseslint.configs.recommended,

  // =========================
  // FRONTEND (browser env)
  // =========================
  {
    files: ["**/*.{js,ts,tsx,jsx}"],
    languageOptions: {
      globals: {
        ...globals.browser
      }
    }
  },

  // =========================
  // NODE / CONFIG FILES
  // =========================
  {
    files: [
      "jest.config.js",
      "**/*.config.js",
      "**/*.config.cjs",
      "**/*.config.mjs"
    ],
    languageOptions: {
      globals: {
        ...globals.node
      }
    }
  },

  // =========================
  // TYPESCRIPT FILES
  // =========================
  {
    files: ["**/*.ts", "**/*.tsx"],
    languageOptions: {
      parser: tseslint.parser,
      parserOptions: {
        project: "./tsconfig.json",
        tsconfigRootDir: import.meta.dirname
      },
      globals: {
        ...globals.browser,
        ...globals.node
      }
    },
    rules: {
      // Ejemplos útiles
      "@typescript-eslint/no-unused-vars": "warn",
      "@typescript-eslint/no-explicit-any": "off"
    }
  },

  // =========================
  // TEST FILES (JEST)
  // =========================
  {
    files: ["**/*.test.{js,ts}", "**/*.spec.{js,ts}"],
    languageOptions: {
      globals: {
        ...globals.node
      }
    },
    rules: {
      // Puedes relajar reglas en tests si quieres
      "no-undef": "off"
    }
  }
];