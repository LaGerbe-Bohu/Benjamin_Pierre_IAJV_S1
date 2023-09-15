#pragma once
#include "../include/States.h"
#include <vector>
#include <unordered_map>
#include "World.h";
class Precondition;
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
	}
	Node(States* myState,const World* myWorld) : State(myState),currentWorld(new World(myWorld)){
	}

	~Node() {
	
		delete currentWorld;
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

	void AddNonMetPrecondition(Precondition* prep) {
		this->nonMetPrecondition.push_back(prep);
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

        World* world;
        std::unordered_map<TypeState,States*> EffectMap;

	public :
        GoapMachine(World* myWorld):world(myWorld) {};

		~GoapMachine() {

			for (auto p : openNode)
			{
				delete p;
			}
		
			EffectMap.clear();
			openNode.clear();
		}

        Node* Execute(States* myRoot);

        std::unordered_map<TypeState, States*> GetEffectMap() {
            
			return EffectMap;
        }

		void AddToHmap(TypeState typeState,States* states) {
			EffectMap[typeState] = states;
		}

        void AddAllOptionsToOpenNode();
};
