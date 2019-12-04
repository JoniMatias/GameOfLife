//
//  CellBoard.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 02/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "CellBoard.hpp"
#include "CellModel.hpp"
#include <algorithm>
#include <vector>

#include <cstdlib>
#include <ctime>


CellBoard::CellBoard(int width, int height) {
	
	currentCells_ = &cells1_;
	nextCells_ = &cells2_;
	
	width_ = width;
	height_ = height;
	
	std::srand(std::time(nullptr));
	
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			CellModel cell = CellModel(CellModel::Status::kDead);
			currentCells_->push_back(cell);
		}
	}
}


CellBoard::~CellBoard() {
	
}

int CellBoard::width() {
	return width_;
}


int CellBoard::height() {
	return height_;
}


CellModel CellBoard::cellAt(int x, int y) {
	int index = indexOfCellAt(x,y);
	return currentCells_->at(index);
}


int CellBoard::indexOfCellAt(int x, int y) {
	return x + y * width_;
}


void CellBoard::toggleCellAt(int x, int y) {
	for (int ix=0; ix<width_; ++ix) {
		for (int iy=0; iy<height_; ++iy) {
			int index = indexOfCellAt(ix, iy);
			CellModel currentCell = currentCells_->at(index);
			if (x == ix && y == iy) {
				CellModel::Status newStatus = currentCell.status() == CellModel::Status::kDead ? CellModel::Status::kAlive : CellModel::Status::kDead;
				CellModel newModel = CellModel(newStatus);
				nextCells_->push_back(newModel);
			} else {
				CellModel newModel = CellModel(currentCell.status());
				nextCells_->push_back(newModel);
			}
		}
	}
	
	swapPointers();
}


void CellBoard::randomize() {
	for (int i=0; i<currentCells_->size(); ++i) {
		CellModel::Status randomStatus = std::rand() % 4 == 0 ? CellModel::Status::kDead : CellModel::Status::kAlive;
		CellModel newCell = CellModel(randomStatus);
		nextCells_->push_back(newCell);
	}
	
	swapPointers();
}


CellVector* CellBoard::newVectorOfNeighboursOf(int x, int y) {
	
	int minX = std::max(0, x-1);
	int maxX = std::min(width_-1, x+1);
	int minY = std::max(0, y-1);
	int maxY = std::min(height_-1, y+1);
	
	CellVector* neighbours = new CellVector();
	
	for (int ix = minX; ix <= maxX; ++ix) {
		for (int iy = minY; iy <= maxY; ++iy) {
			if (ix == x && iy == y) continue;
			int index = indexOfCellAt(ix, iy);
			neighbours->push_back(currentCells_->at(index));
		}
	}
	
	return neighbours;
}
	

void CellBoard::step() {
	
	for (int y = 0; y < height_; ++y) {
		for (int x = 0; x < width_; ++x) {
			int index = indexOfCellAt(x,y);
			CellModel cell = currentCells_->at(index);
			CellVector* neighbours = newVectorOfNeighboursOf(x,y);
			
			CellModel::Status nextStatus = CellModel::determineStatusFromNeighbours(cell.status(), neighbours);
			
			CellModel newCell = CellModel(nextStatus);
			
			nextCells_->push_back(newCell);
			
			delete neighbours;
		}
	}
	
	swapPointers();
	
}


void CellBoard::swapPointers() {
	currentCells_ = currentCells_ == &cells1_ ? &cells2_ : &cells1_;
	nextCells_    = nextCells_    == &cells1_ ? &cells2_ : &cells1_;
	
	nextCells_->clear();
}


