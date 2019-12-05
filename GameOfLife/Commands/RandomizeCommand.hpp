//
//  RandomizeCommand.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 05/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef RandomizeCommand_hpp
#define RandomizeCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class CellBoard;


/*
 RandomizeCommand
 Command for moving the Game of Life in CellBoard one step forward.
 */
class RandomizeCommand: public Command {
	
public:
	RandomizeCommand(CellBoard* board);
	
	virtual void perform();
	
private:
	CellBoard* board_;
	
};



#endif /* RandomizeCommand_hpp */
