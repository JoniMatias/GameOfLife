//
//  ChangeCommand.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "ChangeCommand.hpp"
#include "CellBoard.hpp"



ChangeCommand::ChangeCommand(int x, int y, CellBoard* board) {
	x_ = x;
	y_ = y;
	board_ = board;
}


void ChangeCommand::perform() {
	board_->toggleCellAt(x_, y_);
}
