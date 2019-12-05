//
//  PlayCommand.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 05/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef PlayCommand_hpp
#define PlayCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class CellBoard;


/*
 PlayCommand
 Command for moving the Game of Life in CellBoard forward constantly.
 */
class PlayCommand: public Command {
	
public:
	PlayCommand(CellBoard* board);
	
	virtual void perform();
	virtual bool isFinished();
	
private:
	CellBoard* board_;
	
};


#endif /* PlayCommand_hpp */
