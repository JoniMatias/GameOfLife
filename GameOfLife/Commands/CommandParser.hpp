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

#include "Command.hpp"

class CellBoard;


class CommandParser {
	
	static Command* getCommandFromString(std::string input, CellBoard* board);
	
};


#endif /* CommandParser_hpp */
