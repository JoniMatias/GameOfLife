# GameOfLife
A simple CLI program that implements Convay's Game of Life.

## Compiling

There is no makefile, because gcc supplied with MacOS does not support lambdas. So the only way to compile currently is to add all the files in your favourite C++ IDE, and compile them using that.

## Usage of program

Program requires at the width and height of the game table to be give with CLI arguments.
Those two arguments can be followed by a filepath to a text file that contains commands written in the format specified under the heading *Commands*.
These have to be written in order

## Commands

After each step, the program prompts the user for a command. User can give two kinds of commands:
* Step command is given by leaving the prompt empty, and just pressing enter.
* Toggle command, where user toggles a single cell from dead to alive or vice versa can be given by giving the 0-indexed coordinates for that cell, separated by space.
  * i.e. Command "2 3" would toggle the cell at coordinates (2,3)
