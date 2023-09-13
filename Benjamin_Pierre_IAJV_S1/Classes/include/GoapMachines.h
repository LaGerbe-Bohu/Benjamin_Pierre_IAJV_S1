#pragma once
#include "../include/States.h"
#include <vector>
#include <unordered_map>
class Precondition;
class World;
class Node;

class GoapMachine {
    private:

        // Nodes, preconditions and state vectors.
        std::vector<Node*> openNode;
        std::vector<Precondition*> vecNotMet;
        std::vector<States*> possibleStates;
        World* world;
        std::unordered_map<TypeState,std::vector<States*>> EffectMap;

	public :
        GoapMachine(std::vector<States*> myPossibleStates,World* myWorld):possibleStates(myPossibleStates), world(myWorld) {};

        Node* Execute(States* myRoot);

        std::unordered_map<TypeState, std::vector<States*>> GetEffectMap() const {
            return EffectMap;
        }

        void AddAllOptionsToOpenNode();
};
