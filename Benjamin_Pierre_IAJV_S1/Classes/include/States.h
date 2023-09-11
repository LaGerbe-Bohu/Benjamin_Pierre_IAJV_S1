#pragma once
#include <vector>
#include "Precondition.h"

class World;

class States {
	unsigned int cost;
	std::vector<Precondition> vecPreconditions;

public:
	
	States() {
		std::vector<Precondition> vecPreconditions;
	}

	~States() {
		vecPreconditions.clear();
	}

	void AddPrecondition(Precondition precondition) {
		this->vecPreconditions.push_back(precondition);
	}

	int GetCost() const {
		return this->cost;
	};

	void ( *Action )( World* world);  // Function pointer to the action
	// /*Fonction de précondition */

};
