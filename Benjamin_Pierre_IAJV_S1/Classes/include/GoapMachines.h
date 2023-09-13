#pragma once
#include <vector>

class Precondition;
class States;
class World;

class Node {
    private:
        int heuristic;
        World* currentWorld;
        States* State;
        Node* prev;

    public:
        Node(int myHeuristic, States* myState,World* myWorld) : heuristic(myHeuristic), State(myState), currentWorld(myWorld) {};

        Node(States* myState, World* myWorld) : State(myState), currentWorld(myWorld) {}

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

        void SetHeuristic(int i) {
            this->heuristic = i;
        }

        void AddHeuristic(int i) {
            this->heuristic += i;
        }

        int GetHeuristic() {
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

	public:
        GoapMachine(std::vector<States*> myPossibleStates,World* myWorld):possibleStates(myPossibleStates), world(myWorld) {};

        Node* Execute(States* myRoot);

        void AddAllOptionsToOpenNode();
};
