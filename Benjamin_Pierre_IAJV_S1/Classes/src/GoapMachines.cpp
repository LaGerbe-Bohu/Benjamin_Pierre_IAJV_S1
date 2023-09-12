#include "../include/GoapMachines.h"
#include "../include/States.h"
#include "../include/World.h"
#include <limits>
#include <cassert>

Node* GoapMachine::Execute( States* myRoot) {

	World myWorld = world;
	Node* currentState = new Node(myRoot, new World(myWorld));
	currentState->SetPrev(nullptr);

	while (myRoot->NonMetPreconditions( &myWorld) > 0) {
		
		int myHeuristique = std::numeric_limits<int>::max();
		for (int i = 0; i < possibleStates.size(); i++)
		{
			World* tmpWorld = new World(myWorld);
			Node* n = new Node(possibleStates[i], tmpWorld);
			n->SetPrev(currentState);
			if (n->GetState()->NonMetPreconditions(tmpWorld) <= 0) {
				n->GetState()->Action(tmpWorld);
			}

			n->SetHeuristique(n->PathNonMetPreconditions(tmpWorld));
			openNode.push_back(n);
		}
		
		int idx;
		for (int i = 0; i < openNode.size(); i++)
		{
			if (openNode[i]->GetHeuristique() < myHeuristique) {
				idx = i;
				myHeuristique = openNode[i]->GetHeuristique();
			}
		}

		currentState = openNode[idx];
		openNode.erase(openNode.begin() + idx);
		myWorld = currentState->GetWorld();

		if (currentState->GetState()->GetOnce()) {
			possibleStates.erase(possibleStates.begin() + 1);
		}
		
	}

	return currentState;
}

void GoapMachine::AddAllOptionsToOpenNode() {
	
	
}


int Node::PathNonMetPreconditions(const World* world) {

	int myNbResult = 0;
	Node *idx = this;
	while (idx != nullptr) {
	
		myNbResult += idx->GetState()->NonMetPreconditions(world);
		idx = idx->prev;
	}

	return myNbResult;
}

