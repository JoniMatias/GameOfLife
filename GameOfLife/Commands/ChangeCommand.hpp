//
//  ChangeCommand.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef ChangeCommand_hpp
#define ChangeCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class CellBoard;

/*
 ChangeCommand
 Command for changing one cell in CellBoard to its opposite value.
 */
class ChangeCommand: public Command {
	
public:
	ChangeCommand(int x, int y, CellBoard* board);
	
	virtual void perform();
	
private:
	int x_;
	int y_;
	CellBoard* board_;
	
};


#endif /* ChangeCommand_hpp */
