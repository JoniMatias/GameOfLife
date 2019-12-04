//
//  ArgumentChecker.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef ArgumentChecker_hpp
#define ArgumentChecker_hpp

#include <stdio.h>


/*
 arguments namespace
 Contains functions to parse and validate command line arguments passed to the program.
 */
namespace arguments {

	struct Arguments {
	private:
		long width_;
		long height_;
		bool valid_;
	public:
		Arguments(long width, long height, bool valid) { width_=width; height_=height; valid_=valid; };
		long width() { return width_; };
		long height() { return height_; };
		bool isValid() { return valid_; };
	};

Arguments parseArgumentsFromArray(int argc, const char * argv[]);

bool isBoardSizeValid(long width, long height);

}


#endif /* ArgumentChecker_hpp */
