#pragma once
#include <vector>

class States {};
class Precondition {};

class StatesMachine {
	std::vector<States*> openNode;
	std::vector<Precondition*> vecNotMet;
};
