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
            cost = 0;
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

        void SetCost(unsigned int myCost) {
            cost = myCost;
        }

        void ( *Action )( World* world){};  // Function pointer to the action
        // /*Fonction de precondition */
};
