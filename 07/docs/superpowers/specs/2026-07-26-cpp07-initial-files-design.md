# CPP07 Initial Files Design

## Scope

Create compile-ready starter files for `ex00`, `ex01`, and `ex02` without
implementing any exercise logic.

## Files

- `ex00`: `Makefile`, `main.cpp`, `whatever.hpp`, `.gitignore`
- `ex01`: `Makefile`, `main.cpp`, `iter.hpp`, `.gitignore`
- `ex02`: `Makefile`, `main.cpp`, `Array.hpp`, `.gitignore`

Each `main.cpp` returns `0`. Each header contains only an include guard.
Each `.gitignore` ignores `*.o` and that exercise's executable.

## Build

Follow the Module 06 Makefile pattern with C++98 warning flags and the existing
Docker-based `format` target. The executable names are `whatever`, `iter`, and
`array`. Since templates are defined in headers, each exercise initially has
only `main.cpp` in `SRCS`.

## Verification

Run `make` and `make fclean` in all three exercise directories.
