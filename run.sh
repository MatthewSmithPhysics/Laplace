#!/bin/bash

echo Compiling . . .
g++ -o laplace main.cpp report.cpp solver.cpp grid.cpp includes.cpp
echo Running main program . . . 
./laplace
echo Performing analysis . . .
python3 analysis.py
