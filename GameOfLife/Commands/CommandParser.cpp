//
//  CommandParser.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "CommandParser.hpp"
#include <cstdlib>
#include <string>
#include <vector>

#include "Commands.hpp"
#include "StringFuncs.hpp"


Command* CommandParser::newCommandFromString(std::string input, CellBoard* board) {
	
	if (input.length() == 0) {
		return new StepCommand(board);
	} else if (input.compare("play") == 0) {
		return new PlayCommand(board);
	} else if (input.compare("random") == 0) {
		return new RandomizeCommand(board);
	} else if (stringfuncs::stringContainsOnlyNumbersAndSpaces(input)) {
		std::vector<std::string> components = stringfuncs::splitString(input, ' ');
		if (components.size() == 2) {
			int x = stoi(components[0]);
			int y = stoi(components[1]);

			return new ChangeCommand(x, y, board);
		}
	}
	
	return nullptr;
	
}

