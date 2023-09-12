#pragma once
#include <vector>

class Precondition;
class States;
class World;

class Node {
	int heuristique;
	World* currentWorld;
	States* State;
	Node* prev;

public:
	Node(int myHeuristique,  States* myState,World* myWorld) :heuristique(myHeuristique), State(myState), currentWorld(myWorld) {};
	Node( States* myState, World* myWorld) : State(myState), currentWorld(myWorld) {}
	
	~Node() {
		delete currentWorld;
		delete State;
	}

	World* GetWorld() {
		return this->currentWorld;
	};

	void SetPrev(Node* myNode) {
		this->prev = myNode;
	}

	States* GetState() {
		return this->State;
	}



	Node* GetPrev() {
		return this->prev;
	}

	void SetHeuristique(int i) {
		this->heuristique = i;
	}

	void AddHeuristique(int i) {
		this->heuristique += i;
	}

	int GetHeuristique() {
		return this->heuristique;
	}

	int PathNonMetPreconditions(const World* world);
};

class GoapMachine {
	
	std::vector<Node*> openNode;
	std::vector<Precondition*> vecNotMet;
	std::vector<States*> possibleStates;
	World* world;

	public :
	GoapMachine(std::vector<States*> myPossibleStates,World* myWorld):possibleStates(myPossibleStates), world(myWorld) {};

	Node* Execute(States* myRoot);

	void AddAllOptionsToOpenNode();

};