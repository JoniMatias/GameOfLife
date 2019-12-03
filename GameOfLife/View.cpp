//
//  View.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 03/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "View.hpp"
#include "CellBoard.hpp"

#include <cstdlib>
#include <iostream>


void View::drawBoard(CellBoard* board) {
	
	std::system("clear");
	
	for (int y=0; y<board->height(); ++y) {
		for (int x=0; x<board->width(); ++x) {
			CellModel cell = board->cellAt(x, y);
			char c = charForStatus(cell.status());
			std::cout << c;
		}
		std::cout << std::endl;
	}
	
}

char View::charForStatus(CellModel::Status status) {
	switch (status) {
		case CellModel::Status::kAlive:
			return 'O'; break;
		case CellModel::Status::kDead:
			return ' '; break;
		default:
			return 'E'; break;
	}
}
