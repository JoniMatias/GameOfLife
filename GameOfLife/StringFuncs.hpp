//
//  StringFuncs.hpp
//  GameOfLife
//
//  Created by Joni Rajala on 04/12/2019.
//  Copyright © 2019 Joni Rajala. All rights reserved.
//

#ifndef StringFuncs_hpp
#define StringFuncs_hpp

#include <vector>
#include <string>

namespace stringfuncs {
	std::vector<std::string> splitString(std::string string, char delimiter);

bool stringContainsOnlyNumbers(std::string srt);
bool stringContainsOnlyNumbersAndSpaces(std::string str);
}

#endif /* StringFuncs_hpp */
