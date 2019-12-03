//
//  View.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 03/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include "CellModel.hpp"

class CellBoard;

class View {
public:
	
	void drawBoard(CellBoard* board);
	
private:
	char charForStatus(CellModel::Status status);
};

#endif /* View_hpp */
