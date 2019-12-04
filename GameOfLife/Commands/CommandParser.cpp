//
//  CommandParser.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "CommandParser.hpp"
#include <string>
#include <sstream>


#include "Commands.hpp"


Command* CommandParser::getCommandFromString(std::string input, CellBoard* board) {
	
	if (input.length() == 0) {
		return new StepCommand(board);
	} else {
		if (std::all_of(input.begin(), input.end(), [](char c){ return isdigit(c) || c == ' '; })) {
			
		}
	}
	
	return new NoopCommand();
	
}


