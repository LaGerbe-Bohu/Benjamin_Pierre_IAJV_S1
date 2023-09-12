#include "../include/GoapMachines.h"
#include "States.h"
#include <limits>

void GoapMachine::Execute(const States myRoot) {

	World myWorld = world;
	openNode.push_back(new Node(myRoot,new World(myWorld)));
	Node currentState = myRoot;

	while (myRoot.NonMetPreconditions(myWorld) > 0) {

		for (int i = 0; i < possibleStates.size(); i++)
		{
			World tmpWorld = new World(myWorld);
			Node n(possibleStates[i], tmpWorld);
			n.SetPrev(currentState);
			if (n.GetState().NonMetPreconditions(tmpWorld) <= 0) {
				n.GetState().Action(tmpWorld);
			}

			n.GetState().SetHeuristique(n.PathNonMetPreconditions(tmpWorld));
			openNode.push_back(s);
		}

		int myHeuristique = std::numeric_limits<int>::max();
		int idx;
		for (i = 0; i < openNode.size(); i++)
		{
			if (openNode[i]->GetHeuristique() < myHeuristique) {
				idx = i;
				myHeuristique = openNode[i]->GetHeuristique();
			}
		}

		currentState = openNode[idx];
		openNode.erase(openNode.begin() + idx);
		myWorld = currentState.GetWorld();
	}
	
}

void GoapMachine::AddAllOptionsToOpenNode() {
	
	for (int i = 0; i < possibleStates.size(); i++)
	{
		States s = possibleStates[i];
		s.SetHeuristique(s.pre)
		openNode.push_back();
		
	}
}

int Node::PathNonMetPreconditions(const World* world) {

	int myNbResult = 0;
	Node* idx = *this;
	while (idx != null) {
		myNbResult += State->NonMetPreconditions();
		idx = idx->prev;
	}

	return myNbResult;
}


