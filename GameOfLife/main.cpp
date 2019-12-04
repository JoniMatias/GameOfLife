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
	
	while (true) {
		view.drawBoard(&board);
		std::cout << "Prompt > ";
		
		std::string input;
		std::getline(std::cin, input);
		
		parseAndPerformCommand(input, &board);
	}
	
	
	return 0;
}
