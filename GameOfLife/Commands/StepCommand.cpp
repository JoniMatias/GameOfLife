//
//  StepCommand.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "StepCommand.hpp"
#include "CellBoard.hpp"


StepCommand::StepCommand(CellBoard* board) {
	board_ = board;
}

void StepCommand::perform() {
	board_->step();
}
