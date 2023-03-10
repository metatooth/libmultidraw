# Multidraw

A multi-platform implementation of John Vlissides' Unidraw framework using FLTK.

## Getting Started

Install dependencies:
* conan
* cmake
* build-essentials
* clang
* clang-tidy

```$ git clone libmultidraw```
```$ cd libmultidraw```
```$ mkdir _build && cd _build```
```$ conan install -s compiler=clang -s compiler.version=14 ..```
```$ cmake ..```
```$ make```