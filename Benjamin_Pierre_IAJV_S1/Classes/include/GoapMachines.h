#pragma once
#include <vector>

class Precondition;
class World;

class Node {
	int heuristique;
	World* currentWorld;
	States* State;
	Node* prev;

public:
	Node(int myHeuristique, States* myState,World* myWorld) :myHeuristique(heuristique),myState(State),myWorld(World) {};
	Node(States* myState, World* myWorld) : myState(State), myWorld(World) {}

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

	void GetPrev() {
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
	World world;

	public :
	GoapMachine(std::vector<States*> myPossibleStates,World myWorld):possibleStates(myPossibleStates),myWorld(world) {};

	void Execute(const States myRoot);

	void AddAllOptionsToOpenNode();

};