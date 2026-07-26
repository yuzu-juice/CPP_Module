# CPP07 Initial Files Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Create compile-ready starter files for CPP07 exercises without implementing exercise logic.

**Architecture:** Each exercise is independent and contains one empty `main.cpp`, one guarded template header, one Module 06-style Makefile, and one minimal `.gitignore`.

**Tech Stack:** C++98, GNU Make

## Global Constraints

- Compile with `c++ -Wall -Wextra -Werror -pedantic -std=c++98`.
- Do not implement exercise logic.
- Do not create commits.

---

### Task 1: Create and verify all exercise starters

**Files:**
- Create: `ex00/Makefile`, `ex00/main.cpp`, `ex00/whatever.hpp`, `ex00/.gitignore`
- Create: `ex01/Makefile`, `ex01/main.cpp`, `ex01/iter.hpp`, `ex01/.gitignore`
- Create: `ex02/Makefile`, `ex02/main.cpp`, `ex02/Array.hpp`, `ex02/.gitignore`

**Interfaces:**
- Consumes: None
- Produces: executables `whatever`, `iter`, and `array`

- [ ] **Step 1:** Create the listed files with empty mains, include guards, Module 06-style Makefiles, and minimal ignore rules.
- [ ] **Step 2:** Run `make` in `ex00`, `ex01`, and `ex02`; expect all commands to exit `0`.
- [ ] **Step 3:** Run `make fclean` in all three directories; expect generated objects and executables to be removed.
- [ ] **Step 4:** Inspect `git status --short`; expect only uncommitted CPP07 source and documentation files.
