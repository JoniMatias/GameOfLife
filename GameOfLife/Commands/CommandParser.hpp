//
//  CommandParser.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef CommandParser_hpp
#define CommandParser_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "Command.hpp"

class CellBoard;

/*
 CommandParser
 Factory for creating Command object from user inputted strings.
 Parses the string, determines which kind of Command should be generated and returns that Command.
 @returns: a pointer to a generated Command. Receiver is responsible for destroying the object.
 */
class CommandParser {
public:
	static Command* newCommandFromString(std::string input, CellBoard* board);
	
};


#endif /* CommandParser_hpp */
