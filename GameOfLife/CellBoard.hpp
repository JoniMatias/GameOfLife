//
//  CellBoard.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 02/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef CellBoard_hpp
#define CellBoard_hpp

#include <vector>
#include "CellModel.hpp"

/*
	CellBoard
	Model for storing and updating cells for Convay's Game of Life.
*/

using CellVector = std::vector<CellModel>;

class CellBoard {
	
public:
	CellBoard(int width, int height);

	CellModel cellAt(int x, int y);
	void toggleCellAt(int x, int y);
	
	void randomize();
	void update();
	
	int width();
	int height();
	
	virtual ~CellBoard();
	
private:
	
	CellVector cells1_;
	CellVector cells2_;
	
	CellVector* currentCells_;
	CellVector* nextCells_;
	
	void swapPointers();
	
	int height_;
	int width_;
	
	int indexOfCellAt(int x, int y);
	CellVector* newVectorOfNeighboursOf(int x, int y);
	
	
};


#endif /* CellBoard_hpp */
