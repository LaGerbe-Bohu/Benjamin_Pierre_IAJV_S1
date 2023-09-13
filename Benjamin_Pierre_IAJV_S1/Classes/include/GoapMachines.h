#pragma once
#include "../include/States.h"
#include <vector>
#include <unordered_map>
class Precondition;
class States;
class World;

class Node {
    private:
        int heuristic;
        World* currentWorld;
        States* State;
        Node* prev;
        std::vector<Precondition* > nonMetPrecondition;

public:
	Node(int myHeuristic, States* myState, World* myWorld) : heuristic(myHeuristic), State(myState), currentWorld(myWorld) {
		this->nonMetPrecondition = myState->vecPreconditions;
	}
	Node(States* myState, World* myWorld) : State(myState), currentWorld(myWorld) {
		this->nonMetPrecondition = myState->vecPreconditions;
	}

	~Node() {
		delete currentWorld;
		delete State;
	}

	World* GetWorld() const {
		return this->currentWorld;
	};

	void SetPrev(Node* myNode) {
		this->prev = myNode;
	}

	States* GetState() const {
		return this->State;
	}

	std::vector<Precondition*> GetNonMetPrecondition() const {
		return nonMetPrecondition;
	}

	void SetNonMetPrecondition(std::vector<Precondition*> nonMet) {
		nonMetPrecondition = nonMet;
	}

	bool IsInThePath(States* myNode);

	void SimulatePath( World* myWorld);

	Node* GetPrev() {
		return this->prev;
	}

	void SetHeuristique(int i) {
		this->heuristic = i;
	}

	void AddHeuristique(int i) {
		this->heuristic += i;
	}

	int GetHeuristique() const {
		return this->heuristic;
	}

	int PathNonMetPreconditions(const World* world);
};

class GoapMachine {
    private:
        std::vector<Node*> openNode;
        std::vector<Precondition*> vecNotMet;
        std::vector<States*> possibleStates;
        World* world;
        std::unordered_map<TypeState,std::vector<States*>> EffectMap;

	public :
        GoapMachine(std::vector<States*> myPossibleStates,World* myWorld):possibleStates(myPossibleStates), world(myWorld) {};

        Node* Execute(States* myRoot);

        std::unordered_map<TypeState, std::vector<States*>> GetEffectMap() {
            return EffectMap;
        }

        void AddAllOptionsToOpenNode();
};
