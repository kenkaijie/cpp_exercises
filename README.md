# C++ Excercises

This repo is designed to house many C++ excercises. It is designed to also check them for validity. It serves as a C++ playground for snippets and libraries.

Note that some snippets do depend on libraries found only on computers and is not necessarily embedded friendly.

## Project Structure

Every individual excercise is a library that gets compiled into what is essentially a unit test runner (googletest). Some excercises have unit tests, but others are validated by the fact they compile.

## Building on Computers

Typically build in a "./build" folder. Run mkdir build, cd build, cmake ../ then make