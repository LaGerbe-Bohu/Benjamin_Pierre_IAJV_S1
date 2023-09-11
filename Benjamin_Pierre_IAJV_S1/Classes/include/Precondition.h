#pragma once
#include <vector>
#include <string>

class Precondition
{
	std::string label;
	public :
	
	std::string GetLabel()const {
		return label;
	}

	bool(*Condition)(/*World*/);
};
