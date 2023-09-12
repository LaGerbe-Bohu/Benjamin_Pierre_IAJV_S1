#pragma once
#include <vector>
#include "Precondition.h"

class World;

class States {
	unsigned int cost;
	std::vector<Precondition> vecPreconditions;

	public:
	States() {
		
	}

	~States() {
		vecPreconditions.clear();
	}

	void AddPrecondition(const Precondition* precondition) {
		this->vecPreconditions.push_back(*precondition);
	}

	int GetCost() const {
		return this->cost;
	};


	std::vector<Precondition> GetPreconditions() const {
		return this->vecPreconditions;
	}

	int NonMetPreconditions(const World*);

	void ( *Action )( World* world);  // Function pointer to the action
	// /*Fonction de précondition */

};
