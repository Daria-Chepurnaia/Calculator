
#  Calculator CLI
![CMake Build](https://github.com/Daria-Chepurnaia/Calculator/actions/workflows/cmake.yml/badge.svg)

### 📚 Description

Calculator CLI is a command-line C++ application that evaluates arithmetic and algebraic expressions.  
It supports numbers, variables, parentheses, basic operations (`+`, `-`, `*`, `/`), and unary minus.

---

### ✨ Supported features

- Floating point numbers (e.g., `3.14`, `.5`, `5.`)
- Variables (`x`, `y`) with user-provided input
- Parentheses to override operator precedence
- Unary minus in front of numbers or parentheses
- Error handling (syntax errors, division by zero, invalid input)
- Display parsed expressions with parentheses to reflect operator precedence

---

### 📂 Project structure

```
calculator/
├── main.cpp
├── nodes/              # Expression tree nodes (Value, Sum, Subtract, etc.)
├── parser/             # Lexical and syntax analysis:
│   ├── Tokenizer        # Converts expression string into tokens (numbers, operators, variables)
│   └── ExpressionParser # Builds an abstract syntax tree (AST) from tokens
├── utils/              # VariableInput manager
├── tests/              # Tests using GoogleTest
├── CMakeLists.txt
└── README.md
```

---
### 📥 Cloning the repository

```bash
git clone git@github.com:Daria-Chepurnaia/Calculator.git
cd Calculator
```


---
### ⚙️ Building the project

Requirements:

- CMake >= 3.10
- C++17-compatible compiler
- GoogleTest (automatically downloaded or locally included)

**Commands:**

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

---

### ▶️ Running the calculator

```bash
./calculator.exe
```

Example:

```
Enter expression (or 'exit'): (2 + 3) * 4
Parsed: ((2.000000 + 3.000000) * 4.000000)
Result: 20
```

If the expression contains variables:

```
Enter expression (or 'exit'): x + 2
Enter value for variable 'x': 5
Parsed: (5.000000 + 2.000000)
Result: 7
```

---

### 🧪 Running tests

In the `build/` folder:

```bash
ctest
```

Tests cover:

- Token parsing for numbers, operators, parentheses
- Expression evaluation respecting operator precedence
- Error handling for invalid inputs
- Variable resolution logic

---

### 📝 Additional notes

- Variable names must consist of **only uppercase or lowercase letters** (`a`, `z`, `A`, `Z`).
- **Case sensitivity** is enforced: `x` and `X` are treated as different variables.
- A valid variable value must be an **integer** or a **floating-point number**.
- If a variable input is not a valid number, **the expression processing will terminate with an error**.

---
