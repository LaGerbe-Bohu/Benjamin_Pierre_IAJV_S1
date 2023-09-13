#pragma one
#include <vector>
#include "Precondition.h"
class States {
    private:

	int cost;
    TypeState typeState;
    std::string label;
 
    public:

    States(std::string myLabel, TypeState myTypeStape,int myCost) :label(myLabel), typeState(myTypeStape), cost(myCost) {
    };

    std::string GetLabel() {
        return label;
    }

    unsigned int GetCost() const {
        return cost;
    }

	// /*Fonction de précondition */
    void SetCost(unsigned int myCost) {
        cost = myCost;
    }

    void ( *Action )( World* world){};  // Function pointer to the action
        // /*Fonction de precondition */
};
