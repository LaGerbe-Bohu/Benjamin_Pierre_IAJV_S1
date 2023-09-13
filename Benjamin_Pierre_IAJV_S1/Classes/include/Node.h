#ifndef BENJAMIN_PIERRE_IAJV_S1_NODE_H
#define BENJAMIN_PIERRE_IAJV_S1_NODE_H

#include "World.h"
#include "States.h"

class Node {
private:
    int heuristic;
    World* currentWorld;
    States* State;
    Node* prev;
    std::vector<Precondition* > nonMetPrecondition;

public:
    Node(int myHeuristic, States* myState, World* myWorld) : heuristic(myHeuristic), State(myState), currentWorld(myWorld) {
        this->nonMetPrecondition = myState->GetPreconditions();
    }
    Node(States* myState, World* myWorld) : State(myState), currentWorld(myWorld) {
        this->nonMetPrecondition = myState->GetPreconditions();
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

    void SetNonMetPrecondition(std::vector<Precondition*>& nonMet) {
        nonMetPrecondition = nonMet;
    }

    bool IsInThePath(States* myNode);

    void SimulatePath( World* myWorld);

    Node* GetPrev() const {
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

#endif //BENJAMIN_PIERRE_IAJV_S1_NODE_H
