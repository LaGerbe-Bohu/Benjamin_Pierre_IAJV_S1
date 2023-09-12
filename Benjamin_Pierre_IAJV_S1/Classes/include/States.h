#pragma one
#include <vector>
#include "Precondition.h"

class World;

class States {
    private:
	unsigned int cost;
	std::vector<Precondition> vecPreconditions;

    public:

    States() {
        vecPreconditions = *(new std::vector<Precondition>);
    }

    ~States() {
        vecPreconditions.clear();
    }

    void AddPrecondition(const Precondition* precondition) {
        this->vecPreconditions.push_back(*precondition);
    }

    unsigned int GetCost() const {
        return cost;
    }

	int NonMetPreconditions(const World*);

	void ( *Action )( World* world);  // Function pointer to the action
	// /*Fonction de précondition */
    void SetCost(unsigned int myCost) {
        cost = myCost;
    }

    void ( *Action )( World* world){};  // Function pointer to the action
        // /*Fonction de precondition */
};
