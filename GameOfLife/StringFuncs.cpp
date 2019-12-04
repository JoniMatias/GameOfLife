//
//  StringFuncs.cpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#include "StringFuncs.hpp"



std::vector<std::string> stringfuncs::splitString(std::string string, char delimiter) {
	
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


bool stringfuncs::stringContainsOnlyNumbers(std::string str) {
	return std::all_of(str.begin(), str.end(), [](char c){ return isdigit(c); });
}

bool stringfuncs::stringContainsOnlyNumbersAndSpaces(std::string str) {
	return std::all_of(str.begin(), str.end(), [](char c){ return isdigit(c) || c == ' '; });
}
