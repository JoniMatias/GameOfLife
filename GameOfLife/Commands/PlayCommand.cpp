//
//  PlayCommand.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 05/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "PlayCommand.hpp"
#include <chrono>
#include <thread>

#include "CellBoard.hpp"


PlayCommand::PlayCommand(CellBoard* board) {
	board_ = board;
}

void PlayCommand::perform() {
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	board_->step();
}

bool PlayCommand::isFinished() {
	return false;
}

