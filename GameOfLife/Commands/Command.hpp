//
//  Command.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>


/*
 Command
 Stub implementation for base class for Game of Life Commands for user.
 Is created such a way that undo could be implemented later.
 */
class Command {
	
public:
	virtual void perform();
	
protected:
	Command();
	
};

#endif /* Command_hpp */
