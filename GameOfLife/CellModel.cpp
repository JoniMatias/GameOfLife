//
//  CellModel.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 02/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "CellModel.hpp"


CellModel::CellModel(Status status) {
	status_ = status;
}



CellModel::Status CellModel::determineStatusFromNeighbours(CellModel::Status currentStatus, std::vector<CellModel>* neighbours) {
	
	int liveCount = 0;
	
	for (CellModel model : *neighbours) {
		if (model.status_ == CellModel::Status::kAlive) {
			liveCount += 1;
		}
	}
	
	if (currentStatus == CellModel::Status::kDead) {
		return liveCount == 3 ? CellModel::Status::kAlive : CellModel::Status::kDead;
	} else {
		switch (liveCount) {
			case 0:
			case 1:
				return CellModel::Status::kDead;
				break;
			case 2:
			case 3:
				return CellModel::Status::kAlive;
				break;
			default:
				return CellModel::Status::kDead;
				break;
		}
	}
	
}
