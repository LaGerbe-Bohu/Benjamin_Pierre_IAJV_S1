#pragma once
#include <vector>
#include <string>

class World;

class Precondition
{
	std::string label;
	int multiplicateur;
	public :
	
	std::string GetLabel()const {
		return label;
	}

	bool(*Condition)(const World* world);
};
