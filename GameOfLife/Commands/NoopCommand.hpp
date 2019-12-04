//
//  NoopCommand.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef NoopCommand_hpp
#define NoopCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class CellBoard;

class NoopCommand: public Command {
	
public:
	virtual void perform();
	
};


#endif /* NoopCommand_hpp */
