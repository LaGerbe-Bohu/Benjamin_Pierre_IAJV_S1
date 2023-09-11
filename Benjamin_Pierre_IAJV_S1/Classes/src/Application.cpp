// Benjamin_Pierre_IAJV_S1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "../include/States.h"
#include "../include/Precondition.h"

void ActionCutWood() {
	std::cout << "je coupe du bois" << std::endl;
}

int main()
{
	Precondition prep;
	prep.Condition = []() -> bool { return true; };

	States state;
	state.AddPrecondition(prep);

	state.Action = ActionCutWood;
	state.Action();
	return 0;
}
