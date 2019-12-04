//
//  ArgumentChecker.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "ArgumentChecker.hpp"

#include <climits>
#include <iostream>
#include <fstream>

#include "StringFuncs.hpp"



arguments::Arguments arguments::parseArgumentsFromArray(int argc, const char * argv[]) {
	
	if (argc < 3) {
		std::cout << "Needs width and height as parameters." << std::endl;
		return arguments::Arguments(0, 0, false);
	}
	
	std::string arg1 = std::string(argv[1]);
	std::string arg2 = std::string(argv[2]);
	
	if (stringfuncs::stringContainsOnlyNumbers(arg1) == false || stringfuncs::stringContainsOnlyNumbers(arg2) == false) {
		std::cout << "Wrong parameter format. Width and height should be integers." << std::endl;
		return arguments::Arguments(0, 0, false);
	}
	
	long width  = strtol(argv[1], nullptr, 10);
	long height = strtol(argv[2], nullptr, 10);
	
	if (arguments::isBoardSizeValid(width, height) == false) {
		std::cout << "Invalid width and height parameters." << std::endl;
		return arguments::Arguments(0, 0, false);
	}
	
	return arguments::Arguments(width, height, true);
}


std::vector<std::string> arguments::parseCommandFileFromArgs(int argc, const char* argv[]) {
	
	std::vector<std::string> commandVector;
	
	if (argc == 4) {
		std::string filename = std::string(argv[3]);
		std::ifstream filestream(filename);
		
		std::string line;
		while (getline(filestream, line)) {
			commandVector.push_back(line);
		}
	}
	
	return commandVector;
}

bool arguments::isBoardSizeValid(long width, long height) {
	
	if (width == 0 || width == LONG_MAX || width == LONG_MIN) {
		return false;
	} else if (height == 0 || height == LONG_MAX || height == LONG_MIN) {
		return false;
	}
	
	return true;
	
}
