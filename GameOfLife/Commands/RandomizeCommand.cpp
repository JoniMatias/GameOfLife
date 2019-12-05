//
//  RandomizeCommand.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 05/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "RandomizeCommand.hpp"


#include "CellBoard.hpp"


RandomizeCommand::RandomizeCommand(CellBoard* board) {
	board_ = board;
}

void RandomizeCommand::perform() {
	board_->randomize();
}


