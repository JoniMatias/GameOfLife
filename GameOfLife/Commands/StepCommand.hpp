//
//  StepCommand.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef StepCommand_hpp
#define StepCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class CellBoard;


/*
 StepCommand
 Command for moving the Game of Life in CellBoard one step forward.
 */
class StepCommand: public Command {
	
public:
	StepCommand(CellBoard* board);
	
	virtual void perform();
	
private:
	CellBoard* board_;
	
};


#endif /* StepCommand_hpp */
