//
//  View.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 03/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef TerminalView_hpp
#define TerminalView_hpp

#include <stdio.h>
#include "CellModel.hpp"

class CellBoard;

/*
 TerminalView
 The view part of Model-View-Presenter.
 Draws the contents of the CellBoard to terminal. The simplest UI solution.
 */
class TerminalView {
public:
	
	void drawBoard(CellBoard* board);
	
private:
	char charForStatus(CellModel::Status status);
};

#endif /* TerminalView_hpp */
