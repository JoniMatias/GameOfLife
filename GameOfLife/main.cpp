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


void parseAndPerformCommand(std::string str, CellBoard* board) {
	CommandParser parser;
	Command* command = parser.newCommandFromString(str, board);
	if (command != nullptr) {
		command->perform();
		delete command;
	}
}

void mainLoop(CellBoard* board, TerminalView view) {
	
	CommandParser parser;
	Command* command = nullptr;
	
	while (true) {
		view.drawBoard(board);
		
		while (command == nullptr) {
			std::string input = view.promptInput();
			command = parser.newCommandFromString(input, board);
		}
		
		command->perform();
		
		if (command->isFinished()) {
			delete command;
			command = nullptr;
		}
	}
}


int main(int argc, const char * argv[]) {
	
	arguments::Arguments args = arguments::parseArgumentsFromArray(argc, argv);
	std::vector<std::string> lines = arguments::parseCommandFileFromArgs(argc, argv);
	
	if (args.isValid() == false) {
		return 1;
	}
	
	CellBoard board = CellBoard((int)args.width(), (int)args.height());
	TerminalView view;
	
	for (std::string line : lines) {
		parseAndPerformCommand(line, &board);
	}
	
	mainLoop(&board, view);
	
	return 0;
}
