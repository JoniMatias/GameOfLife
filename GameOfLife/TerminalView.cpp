//
//  View.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 03/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "TerminalView.hpp"
#include "CellBoard.hpp"

#include <cstdlib>
#include <iostream>


void TerminalView::drawBoard(CellBoard* board) {
	
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

std::string TerminalView::promptInput() {
	std::cout << "Prompt > ";
	std::string input;
	std::getline(std::cin, input);
	return input;
}


char TerminalView::charForStatus(CellModel::Status status) {
	switch (status) {
		case CellModel::Status::kAlive:
			return 'O'; break;
		case CellModel::Status::kDead:
			return '.'; break;
		default:
			return 'E'; break;
	}
}
