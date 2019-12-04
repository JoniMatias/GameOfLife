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
	Model for storing and updating cells for Convay's Game of Life. Contains the business logic for updating said cells.
*/

using CellVector = std::vector<CellModel>;

class CellBoard {
	
public:
	CellBoard(int width, int height);

	CellModel cellAt(int x, int y);
	void toggleCellAt(int x, int y);
	
	void randomize();
	void step();
	
	int width();
	int height();
	
	virtual ~CellBoard();
	
private:
	
	//The buffer vectors for storing current cells and an empty vector for next cells.
	CellVector cells1_;
	CellVector cells2_;
	
	//Pointers to correct cell vectors. These will be swapped when necessary.
	CellVector* currentCells_;
	CellVector* nextCells_;
	
	void swapPointers();
	
	int height_;
	int width_;
	
	int indexOfCellAt(int x, int y);
	CellVector* newVectorOfNeighboursOf(int x, int y);
	
	
};


#endif /* CellBoard_hpp */
