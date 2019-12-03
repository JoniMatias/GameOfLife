//
//  CellModel.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 02/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef CellModel_hpp
#define CellModel_hpp

#include <vector>

struct CellModel {

public:

	enum class Status {
		kAlive,
		kDead
	};
	
	
	CellModel(Status status);
	
	Status status() { return status_; };
	
	/*Static function that checks the survival and rebirth rules of Game of Life for any cell.
	 @returns: the value that the cell should change to if the given parameters are true.
	 */
	static Status determineStatusFromNeighbours(Status currentStatus, std::vector<CellModel>* neighbours);
	
private:
	Status status_;

};


#endif /* CellModel_hpp */
