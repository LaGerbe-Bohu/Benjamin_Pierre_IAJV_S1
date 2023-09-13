#pragma once
#include <vector>
#include "Precondition.h"

class States {
    private:

	int cost;
    TypeState typeState;
    std::string label;
    std::vector<Precondition*> VecPreconditions;

    public:

    States(std::string myLabel, TypeState myTypeStape,int myCost) :label(myLabel), typeState(myTypeStape), cost(myCost) {
    };

    ~States() {
        VecPreconditions.clear();
    }


    std::string GetLabel() {
        return label;
    }

    TypeState GetTypeState() {
        return typeState;
    }

    unsigned int GetCost() const {
        return cost;
    }

    std::vector<Precondition*> vecPreconditions;

	// /*Fonction de précondition */
    void SetCost(unsigned int myCost) {
        cost = myCost;
    }

    void ( *Action )( World* world){};  // Function pointer to the action
        // /*Fonction de precondition */
};
