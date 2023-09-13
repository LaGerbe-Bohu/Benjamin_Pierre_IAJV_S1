#include "../include/States.h"

int States::NonMetPreconditions(const World* world) {

	int idx = 0;

	for (auto & vecPrecondition : vecPreconditions)
	{
		if (!vecPrecondition.Condition(world)) {
			idx++;
		}
	}
	return idx;
}
