// Benjamin_Pierre_IAJV_S1.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "../include/States.h"
#include "../include/Precondition.h"
#include "../include/World.h"


void ActionCutWood() {
	std::cout << "Cutting wood." << std::endl;
}

void Action

void InitActions() {

}

int main()
{

	Precondition prep;
	prep.Condition = []() -> bool { return true; };

	States state;
	state.AddPrecondition(prep);

	state.Action = ActionCutWood;
	state.Action();

    World world = World();
    std::cout << world.GetBreadCount() << " bread" << std::endl;
    world.SetBreadCount(5);
    std::cout << world.GetBreadCount() << " bread" << std::endl;
    return 0;

}
