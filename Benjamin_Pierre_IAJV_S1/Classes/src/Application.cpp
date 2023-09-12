// Benjamin_Pierre_IAJV_S1.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "../include/States.h"
#include "../include/Precondition.h"
#include "../include/World.h"

void ActionCutWood() {
	std::cout << "je coupe du bois" << std::endl;
}

void ActionCreateVillager(  World* myWorld) {
	myWorld->SetVillagerCount(myWorld->GetVillagerCount() + 1);
	myWorld->SetBreadCount(myWorld->GetBreadCount() - 1);
}

void InitStates() {
	States CreateVillager;
	CreateVillager.Action = ActionCreateVillager;

	Precondition prep;
	prep.Condition = [](const World* w) -> bool { 
		return w->GetBreadCount() > 0 ; 
	};	

	CreateVillager.AddPrecondition(&prep);

}

int main()
{
	InitStates();
	
	World world = World();
	std::cout << " Bread : " << world.GetBreadCount() << std::endl;
	std::cout << " Villager : " << world.GetVillagerCount() << std::endl;
	std::cout << " Warrior : " << world.GetWarriorCount() << std::endl;
	std::cout << " Warrior : " << world.GetEnemyLivesCount() << std::endl;


    return 0;
}
