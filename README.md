# GameOfLife
A simple CLI program that implements Convay's Game of Life.

## Compiling

There is no makefile, because gcc supplied with MacOS does not support lambdas. So the best way to compile currently is to clone the repository using your favourite C++ IDE, and compile them using that. If your IDE does not support cloning, and you have generate your own compile command, then I'm sorry.

## Usage of program

Program requires at the width and height of the game table to be give with CLI arguments.
Those two arguments can be followed by a filepath to a text file that contains commands written in the format specified under the heading *Commands*. This file is so that users can create starting state for the Game of Life by listing alive cells. 

These CLI arguments must be written in the following order \[width\] \[height\] \[filepath\].

## Commands

After each step, the program prompts the user for a command. User can give four kinds of commands:
* Step command is given by leaving the prompt empty, and just pressing enter. This moves the game of life one step forward.
* Toggle command, where user toggles a single cell from dead to alive or vice versa can be given by giving the 0-indexed coordinates for that cell, separated by space.
  * i.e. Command "2 3" would toggle the cell at coordinates (2,3)
* Play command is issued by typing "play" into the prompt. This command plays the game of life one step at a time and never finishes. Using this command puts the program in a loop, where no more prompts appear.
* Randomize command is issued by typing "random" into the prompt. Randomize Command creates a new random table of cells. The size of this table remains the same as before.

Currently the only way to close the application is to kill it with either Ctrl+C or Ctrl+Z.

