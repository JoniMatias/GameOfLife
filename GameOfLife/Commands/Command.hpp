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
 Stub implementation for base class for Commands that user can give.
 Is created such a way that it is easily expandable to include undo funtionality.
 */
class Command {
	
public:
	virtual void perform();
	virtual bool isFinished();
	
protected:
	Command();
	
};

#endif /* Command_hpp */
