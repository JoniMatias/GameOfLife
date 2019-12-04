//
//  main.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 02/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include <iostream>
#include <string>
#include <climits>

#include "CellBoard.hpp"
#include "TerminalView.hpp"
#include "CommandParser.hpp"
#include "ArgumentChecker.hpp"


bool isBoardSizeValid(long width, long height) {
	
	if (width == 0 || width == LONG_MAX || width == LONG_MIN) {
		return false;
	} else if (height == 0 || height == LONG_MAX || height == LONG_MIN) {
		return false;
	}
	
	return true;
	
}


int main(int argc, const char * argv[]) {
	
	arguments::Arguments args = arguments::parseArgumentsFromArray(argc, argv);
	
	if (args.isValid() == false) {
		return 1;
	}
	
	CellBoard board = CellBoard((int)args.width(), (int)args.height());
	TerminalView view;
	CommandParser parser;
	board.randomize();
	
	while (true) {
		
		view.drawBoard(&board);
		
		std::string input;
		std::getline(std::cin, input);
		
		Command* command = parser.newCommandFromString(input, &board);
		if (command != nullptr) {
			command->perform();
			delete command;
		}
	}
	
	
	return 0;
}
