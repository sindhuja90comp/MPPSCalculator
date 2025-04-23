# MPPSCalculator Application Report
This program calculates basic statistics (mean, median, and mode) on a list of integers. The program is implemented in C, OCaml, and Python, demonstrating a different paradigm in each language.

## Table of Contents
1. [Overview](#1-overview)
2. [Project Structure](#2-project-structure)
3. [Running the Python Application](#3-running-the-python-application)
4. [Running the C++ Application](#4-running-the-c-application)
5. [Running the OCaml Application](#5-running-the-ocaml-application)
6. [Additional Information](#6-additional-information)

---

## 1. Overview
The **MPPSCalculator** application is a multi-paradigm program designed to calculate basic statistics—**mean**, **median**, and **mode**—on a list of integers. The project demonstrates the same functionality implemented in three different programming languages, each showcasing a unique programming paradigm:
- **C++** (Object-Oriented Programming)
- **Python** (Scripting/Interpreted Language)
- **OCaml** (Functional Programming)

This project provides an educational comparison of how the same functionality can be achieved using different programming paradigms and languages.

---

## 2. Project Structure
The repository is structured as follows:
```
MPPSCalculator/
├── cpp/          # Contains the C++ implementation
├── python/       # Contains the Python implementation
├── ocaml/        # Contains the OCaml implementation
└── README.md     # Documentation for the project
```

Each subdirectory (`cpp`, `python`, `ocaml`) contains language-specific implementations and associated files like source code, dependencies, and build instructions.

---

## 3. Running the Python Application
To execute the Python implementation:
1. Navigate to the `python` directory:
   ```bash
   cd python
   ```
2. Ensure you have Python installed (version ≥ 3.6).
3. Run the script with the following command:
   ```bash
   python mpps_calculator.py
   ```
4. Input the list of integers as prompted, and the application will output the mean, median, and mode.

---

## 4. Running the C++ Application
To execute the C++ implementation:
1. Navigate to the `cpp` directory:
   ```bash
   cd cpp
   ```
2. Compile the C++ code using a compatible C++ compiler (e.g., `g++`):
   ```bash
   g++ -o mpps_calculator mpps_calculator.cpp
   ```
3. Run the compiled program:
   ```bash
   ./mpps_calculator
   ```
4. Input the list of integers as prompted, and the application will output the mean, median, and mode.

---

## 5. Running the OCaml Application
To execute the OCaml implementation:
1. Navigate to the `ocaml` directory:
   ```bash
   cd ocaml
   ```
2. Compile the OCaml code using the OCaml compiler:
   ```bash
   ocamlc -o mpps_calculator mpps_calculator.ml
   ```
3. Run the compiled program:
   ```bash
   ./mpps_calculator
   ```
4. Input the list of integers as prompted, and the application will output the mean, median, and mode.

---

## 6. Additional Information
- **Multi-Paradigm Comparison**: This project highlights differences in syntax, structure, and approach between object-oriented, scripting, and functional programming paradigms.
- **Dependencies**:
  - **Python**: Requires Python ≥ 3.6. Additional libraries may be specified in a `requirements.txt` file.
  - **C++**: Requires a C++ compiler supporting the C++11 standard or later.
  - **OCaml**: Requires the OCaml compiler installed on your system.

For additional details, refer to the `README.md` file in the repository, which contains further documentation about the project.
