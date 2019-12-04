//
//  main.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 02/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include <iostream>
#include <string>

#include "CellBoard.hpp"
#include "TerminalView.hpp"
#include "CommandParser.hpp"

int main(int argc, const char * argv[]) {
	
	int width  = atoi(argv[1]);
	int height = atoi(argv[2]);
	
	CellBoard board = CellBoard(width, height);
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
