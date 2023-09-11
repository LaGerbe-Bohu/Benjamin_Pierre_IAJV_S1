// Benjamin_Pierre_IAJV_S1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "../include/World.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
    World world = World();
    std::cout << world.GetBreadCount() << " bread" << std::endl;
    world.SetBreadCount(-11);
    std::cout << world.GetBreadCount() << " bread" << std::endl;
    return 0;
}
