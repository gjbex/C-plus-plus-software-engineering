C++ is widely used in many contexts.
This training focusses on software engineering aspects of C++ such
as building software, linting, testing libraries and applications,
and so on.
Also, best practices are discussed such as design patterns.


## Learning outcomes

When you complete this training you will be able to

  * assess code quality;
  * build software using CMake;
  * perform static code analysis and interpret the results;
  * write unit tests using Catch2;
  * write functional tests using CTest;
  * use C++ package managers such as Conan or vcpkg;
  * apply a number of design patterns that are useful in scientific programming;
  * use STL algorithms and ranges more effectively in an idiomatic style.


## Schedule

Total duration: 4 hours

  | Subject                                          | Duration |
  |--------------------------------------------------|----------|
  | introduction and motivation                      |  5 min.  |
  | coding best practices                            | 20 min.  |
  | exception handling                               | 10 min.  |
  | basic usage of CMake                             | 20 min.  |
  | linking to libraries using CMake                 | 10 min.  |
  | building OpenMP and MPI applications using CMake |  5 min.  |
  | hands-on session                                 | 20 min.  |
  | coffee break                                     | 10 min.  |
  | static code analysis using Clang-tidy/cppcheck   | 20 min.  |
  | writing unit tests with Catch2                   | 20 min.  |
  | behavior-driven development with Catch2          | 10 min.  |
  | hands-on session                                 | 20 min.  |
  | package management with Conan/vcpkg              | 10 min.  |
  | design pattern examples                          | 20 min.  |
  | functional programming using ranges              | 15 min.  |
  | hands-on session                                 | 20 min.  |
  | wrap up                                          |  5 min.  |


## Training materials

Slides and source code are available in the
 [GitHub repository](https://github.com/gjbex/C-plus-plus-software-engineering),
as well as example code and hands-on material.


## Target audience

This training is for you if you already use C++ and want to develop
production-quality software more effectively.


## Prerequisites

You will need experience programming in C++.
This is *not* a training that teaches you how to program in C++ from scratch.

You also need to be familiar with the Bash command line.

More concretely, participants should already be comfortable with the following:

* writing and reading small to medium C++ programs;
* variables, expressions, control flow, functions, and separate compilation;
* header and source files, `#include`, and basic project structure;
* references, `const` correctness, and basic value semantics;
* classes, constructors, member functions, inheritance, and virtual functions;
* exceptions and basic error handling;
* standard-library facilities such as `std::string`, `std::vector`, streams,
  and a few common containers or algorithms;
* reading compiler diagnostics and making small fixes to existing code;
* compiling and running programs from the command line at a basic level.

You do not need prior experience with CMake, Catch2, CTest, clang-tidy,
cppcheck, Conan, vcpkg, or design patterns. Those are part of the training
itself.

### Quick self-assessment

If you can do most of the tasks below without looking up basic C++ syntax, you
are likely ready for this training.

* define a simple class with a constructor and one or two member functions;
* split a small program into a header file and a source file;
* store values in a `std::vector` and loop over them;
* throw and catch a standard exception such as `std::invalid_argument`;
* read a short C++ program that uses references, `const`, and a few STL types;
* compile and run a small C++ program from the command line;
* make a small change to an existing C++ source file and rebuild it;
* read a compiler error or test failure and identify roughly where the problem
  occurred.

If several of these items still feel difficult, the training will probably move
too fast. In that case, it is better to first take a short introductory C++
course or refresh the basics.

### Software and access requirements

To follow hands-on, you need a computer with a C++ development environment
installed. You can of course use an HPC system you have access to as well.


## Level of the Material

For participants who already have basic to intermediate C++ programming
experience, the material in this training is approximately

* Introductory: 15 %
* Intermediate: 45 %
* Advanced: 40 %

These percentages describe the level of the software engineering topics covered
in the training, not the required entry level in C++ itself.


## Trainer(s)

  * Geert Jan Bex ([geertjan.bex@uhasselt.be](mailto:geertjan.bex@uhasselt.be))
