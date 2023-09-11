// Benjamin_Pierre_IAJV_S1.cpp : Defines the entry point for the application.
//

#include <iostream>
<<<<<<< HEAD
#include "../include/States.h"
#include "../include/Precondition.h"
=======
#include "../include/World.h"
>>>>>>> a44eadb084ab3353be3d6fbe3f20fae252fdfbce

void ActionCutWood() {
	std::cout << "je coupe du bois" << std::endl;
}

int main()
{
<<<<<<< HEAD
	Precondition prep;
	prep.Condition = []() -> bool { return true; };

	States state;
	state.AddPrecondition(prep);

	state.Action = ActionCutWood;
	state.Action();
	return 0;
=======
	cout << "Hello CMake." << endl;
    World world = World();
    std::cout << world.GetBreadCount() << " bread" << std::endl;
    world.SetBreadCount(-11);
    std::cout << world.GetBreadCount() << " bread" << std::endl;
    return 0;
>>>>>>> a44eadb084ab3353be3d6fbe3f20fae252fdfbce
}
