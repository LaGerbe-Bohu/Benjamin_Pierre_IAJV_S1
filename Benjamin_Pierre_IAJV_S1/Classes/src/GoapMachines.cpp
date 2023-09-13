#include "../include/GoapMachines.h"
#include "../include/States.h"
#include "../include/World.h"
#include <limits>
#include <cassert>


void Node::SimulatePath( World* myWorld) {
	Node* idx = this;
	World* world = new World(myWorld);
	idx->GetState()->Action(world);
	idx = idx->GetPrev();
	while (idx != nullptr) {
		if (idx->GetState()->NonMetPreconditions(world) <= 0) {
			idx->GetState()->Action(world);
		}
		idx = idx->GetPrev();
	}

	this->currentWorld = world;
}


int FindCorrectNode(std::vector<Node*> myOpenNode) {

	assert(myOpenNode.size() > 0);

	bool find = false;
	int heuristique = std::numeric_limits<int>::max();
	int cost = std::numeric_limits<int>::max();
	int idx;
	std::vector<int> possibleNode;
	for (int i = 0; i < myOpenNode.size(); i++)
	{
		if (myOpenNode[i]->GetHeuristique() <= heuristique) {
			possibleNode.push_back(i);
			heuristique = myOpenNode[i]->GetHeuristique();
		}
	}

	assert(possibleNode.size() > 0);

	if (possibleNode.size() == 1) {
		return possibleNode[0];
	}


	for (int i = 0; i < possibleNode.size(); i++)
	{
		if (myOpenNode[possibleNode[i]]->GetState()->GetCost() < cost) {
			idx = possibleNode[i];
			cost = myOpenNode[possibleNode[i]]->GetState()->GetCost();
		}
	}

	return idx;
}


Node* GoapMachine::Execute( States* myRoot) {

	World myWorld = world;
	Node* currentNode = new Node(myRoot, new World(myWorld));
	currentNode->SetPrev(nullptr);
	currentNode->SetHeuristique(currentNode->PathNonMetPreconditions(currentNode->GetWorld()));
	openNode.push_back(currentNode);
	currentNode->SetNonMetPrecondition(currentNode->GetState()->GetPreconditions());

	for (int i = 0; i < openNode.size(); i++)
	{
		for (int j = 0; j < openNode.size(); j++)
		{
			if (openNode[j]->GetHeuristique() <= 0) {
				currentNode = openNode[j];
				return currentNode;
			}
		}

		int idx = FindCorrectNode(openNode);
		currentNode = openNode[idx];
		openNode.erase(openNode.begin() + idx);

		for (int j = 0; j < possibleStates.size(); j++)
		{
			if (!currentNode->IsInThePath(possibleStates[j])) {

				World* tmpWorld = new World(myWorld);
				Node* tmpNode = new Node(possibleStates[j], new World(tmpWorld));
				openNode.push_back(tmpNode);
				tmpNode->SetPrev(currentNode);
				tmpNode->GetState()->Action(tmpWorld);

				std::vector<Precondition*> preconditions;
				for (int i = 0; i < currentNode->GetNonMetPrecondition().size(); i++)
				{
					if (!currentNode->GetNonMetPrecondition()[i]->Condition(tmpWorld)) {
						preconditions.push_back(currentNode->GetNonMetPrecondition()[i]);
						
					}
				}
				for (int i = 0; i < tmpNode->GetState()->GetPreconditions().size(); i++)
				{
					preconditions.push_back(tmpNode->GetState()->GetPreconditions()[i]);
				}

				tmpNode->SetNonMetPrecondition(preconditions);
				tmpNode->SetHeuristique(preconditions.size());
			}
			
		}


		/*
		int heuristique = std::numeric_limits<int>::max();
		int cost = std::numeric_limits<int>::max();
		for (int j = 0; j < openNode.size(); j++)
		{
			if (openNode[j]->GetHeuristique() <=0) {
				currentNode = openNode[j];
				return currentNode;
			}
		}

		int idx = FindCorrectNode(openNode);
		currentNode = openNode[idx];
		openNode.erase(openNode.begin() + idx);

		for (int j = 0; j < possibleStates.size(); j++)
		{
 			if ( !currentNode->IsInThePath(possibleStates[j]) ) {
				World* tmpWorld = new World(currentNode->GetWorld());
				Node* tmpNode = new Node(possibleStates[j], new World(tmpWorld));
				openNode.push_back(tmpNode);
				tmpNode->SetPrev(currentNode);
				tmpNode->SimulatePath(new World(myWorld));
				tmpNode->SetHeuristique(tmpNode->PathNonMetPreconditions(tmpNode->GetWorld()));
			}
		}
		*/
	}

	return currentNode;

	/*
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
			else {

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
	*/
	return currentNode;
}



void GoapMachine::AddAllOptionsToOpenNode() {
	
	
}

bool Node::IsInThePath(States* myState) {
	bool find = false;
	Node* idx = this;

	while (idx != nullptr && !find ) {
		if (idx->GetState() == myState) {
			find = true;
		}
		else {
			idx = idx->GetPrev();
		}
	}

	return find;
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

