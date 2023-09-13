#include "../include/GoapMachines.h"
#include "../include/World.h"
#include <limits>
#include <cassert>
#include "../include/Node.h"

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


	for (int i : possibleNode)
	{
		if (myOpenNode[i]->GetState()->GetCost() < cost) {
			idx = i;
			cost = myOpenNode[i]->GetState()->GetCost();
		}
	}
	return idx;
}

Node* GoapMachine::Execute(States* myRoot) {

	World myWorld = world;
	Node* currentNode = new Node(myRoot, new World(myWorld));
	currentNode->SetPrev(nullptr);
	currentNode->SetHeuristique(currentNode->GetNonMetPrecondition().size());
	openNode.push_back(currentNode);

	for (int i = 0; i < openNode.size(); i++)
	{
		if (openNode[i]->GetHeuristique() <= 0) {
			currentNode = openNode[i];
			return currentNode;
		}

		int idx = FindCorrectNode(openNode);
		currentNode = openNode[idx];
		openNode.erase(openNode.begin() + idx);

		std::vector<States*> state = GetEffectMap()[currentNode->GetState()->GetTypeState()];


		for (auto & j : state)
		{
			Node n(j, new World(currentNode->GetWorld()));
			n.GetState()->Action(n.GetWorld());
			n.SetPrev(currentNode);

			for (auto prep : currentNode->GetState()->GetPreconditions())
			{
					if (!prep->Condition(n.GetWorld(),prep)) {
					n.GetNonMetPrecondition().push_back(prep);
				}
			}
			n.SetHeuristique(n.GetNonMetPrecondition().size());
		}
	}
	return currentNode;
}

void GoapMachine::AddAllOptionsToOpenNode() {

}
