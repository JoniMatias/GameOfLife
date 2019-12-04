//
//  StringFuncs.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "StringFuncs.hpp"



std::vector<std::string> splitString(std::string string, char delimiter) {
	
	std::string::iterator it = string.begin()-1;
	
	std::vector<std::string> substringVector;
	
	do {
		std::string::iterator newBegin = it+1;
		it = std::find_if(newBegin, string.end(), [delimiter](char c){ return c == delimiter; });
		std::string substring = std::string(newBegin, it);
		if (substring.length() > 0 ) {
			substringVector.push_back(substring);
		}
	} while (it != string.end());
	
	return substringVector;
	
}
