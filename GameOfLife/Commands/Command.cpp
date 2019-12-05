//
//  Command.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "Command.hpp"


Command::Command() {
	//Because constructor is protected, it needs to be implemented
}

void Command::perform() {
	
}

bool Command::isFinished() {
	return true;
}
