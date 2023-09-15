#include "../include/GoapMachines.h"
#include "../include/States.h"
#include "../include/World.h"
#include <limits>
#include <cassert>
#include <iostream>
#include <algorithm>

void Node::SimulatePath( World* myWorld) {
	/*Node* idx = this;
	World* world = new World(myWorld);
	idx->GetState()->Action(world);
	idx = idx->GetPrev();
	while (idx != nullptr) {
		if (idx->GetState()->NonMetPreconditions(world) <= 0) {
			idx->GetState()->Action(world);
		}
		idx = idx->GetPrev();
	}

	this->currentWorld = world;*/
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


	if (possibleNode.size() >= 2) {
		if (myOpenNode[possibleNode[0]]->GetHeuristique() > myOpenNode[possibleNode[1]]->GetHeuristique()) {
			possibleNode.erase(possibleNode.begin() + 0);
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

	currentNode->SetHeuristique(currentNode->GetState()->GetVecPrecondition().size());
	openNode.push_back(currentNode);

	for (int i = 0; i < currentNode->GetState()->GetVecPrecondition().size(); i++)
	{
		currentNode->AddNonMetPrecondition(currentNode->GetState()->GetVecPrecondition()[i]);
	}

	while(!openNode.empty())
	{

		for (int i = 0; i < openNode.size(); i++)
		{
			if (openNode[i]->GetHeuristique() <= 0) {
				currentNode = openNode[i];
				return currentNode;
			}
		}

		int idx = FindCorrectNode(openNode);
		currentNode = openNode[idx];


		openNode.erase(openNode.begin() + idx);

		std::vector<States*> state;

		for (int i = 0; i < currentNode->GetNonMetPrecondition().size(); i++)
		{
			Precondition* prep = currentNode->GetNonMetPrecondition()[i];
			TypeState t = currentNode->GetNonMetPrecondition()[i]->GetTypeState();
			States* s = GetEffectMap()[t];

			if (prep->Condition(currentNode->GetWorld(), prep) || (std::find(state.begin(),state.end(),s) != state.end()) ) {
				continue;
			}

			state.push_back(s);
		}


		for (int j = 0; j < state.size(); j++)
		{
			Node* n = new Node(state[j], new World(myWorld));

			for (int k = 0; k < n->GetState()->GetVecPrecondition().size(); k++) {
				Precondition* prep = n->GetState()->GetVecPrecondition()[k];
				if (!prep->Condition(&myWorld, prep)) {
					n->AddNonMetPrecondition(n->GetState()->GetVecPrecondition()[k]);
				}

			}

			n->GetState()->Action(n->GetWorld());
			n->SetPrev(currentNode);

			for (int k = 0; k < currentNode->GetNonMetPrecondition().size(); k++)
			{
				Precondition* prep = currentNode->GetNonMetPrecondition()[k];
				if (!prep->Condition(n->GetWorld(),prep)) {
					n->AddNonMetPrecondition(currentNode->GetNonMetPrecondition()[k]);

				}
			}


			n->SetHeuristique(n->GetNonMetPrecondition().size());
			openNode.push_back(n);

		}

	}

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
/*
	int myNbResult = 0;
	Node *idx = this;
	while (idx != nullptr) {

		myNbResult += idx->GetState()->NonMetPreconditions(world);
		idx = idx->prev;
	}

	return myNbResult;
	*/
	return 0;
}

