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
        States(const std::string& myLabel, TypeState myTypeStape, int myCost) :label(myLabel), typeState(myTypeStape), cost(myCost) {};

        ~States() {
            VecPreconditions.clear();
        }

        std::string GetLabel() const {
            return label;
        }

        std::vector<Precondition*> GetPreconditions() const {
            return VecPreconditions;
        }

        TypeState GetTypeState() const {
            return typeState;
        }

        unsigned int GetCost() const {
            return cost;
        }

        // /*Fonction de precondition */
        void SetCost(int myCost) {
            cost = myCost;
        }

        void ( *Action )(World* world){};  // Function pointer to the action
            // /*Fonction de precondition */
};
