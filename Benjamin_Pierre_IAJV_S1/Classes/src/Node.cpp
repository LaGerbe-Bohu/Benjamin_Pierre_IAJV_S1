#include "../include/Node.h"

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
