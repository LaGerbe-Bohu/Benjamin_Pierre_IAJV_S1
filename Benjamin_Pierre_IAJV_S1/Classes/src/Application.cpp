// Benjamin_Pierre_IAJV_S1.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "../include/States.h"
#include "../include/Precondition.h"
#include "../include/World.h"
#include "../include/GoapMachines.h"

void ActionCutWood() {
	std::cout << "Cutting wood." << std::endl;
}

void ActionCreateVillager(World* myWorld) {
	myWorld->SetVillagerCount(myWorld->GetVillagerCount() + 1);
	myWorld->SetBreadCount(myWorld->GetBreadCount() - 1);
}


void ActionCutWood(World* myWorld) {
    myWorld->SetWoodCount(myWorld->GetWoodCount() + 1);
}

void ActionMineIron(World* myWorld) {
    myWorld->SetIronCount(myWorld->GetIronCount() + 1);
}

void ActionMineGold(World* myWorld) {
    myWorld->SetGoldCount(myWorld->GetGoldCount() + 1);
}

void ActionCreateFarm(World* myWorld) {
    myWorld->SetFarmCount(myWorld->GetFarmCount() + 1);
}

void ActionCreateBread(World* myWorld) {
    myWorld->SetBreadCount(myWorld->GetBreadCount() + 1);
}

void ActionCreateWarrior(World* myWorld) {
    myWorld->SetWarriorCount(myWorld->GetWarriorCount() + 1);
    myWorld->SetGoldCount(myWorld->GetGoldCount() - 1);
}

void ActionAttackEnemy(World* myWorld) {
    myWorld->SetEnemyLivesCount(myWorld->GetEnemyLivesCount() - 10);
    myWorld->SetWarriorCount(myWorld->GetWarriorCount() - 10);
    myWorld->SetEnemyFound(false);
}

void ActionLookForEnemy(World* myWorld) {
    myWorld->SetEnemyFound(true);
}

void InitStates() {
    
}

int main()
{
	//InitStates();

    // Villager state
    
    #pragma region StatesInit
    States CreateVillager("Create a villager");

    Precondition prepVillager;
    prepVillager.Condition = [](const World* w) -> bool {
        return w->GetBreadCount() > 0;
    };
    CreateVillager.AddPrecondition(&prepVillager);

    CreateVillager.Action = ActionCreateVillager;

    // Wood state
    States CutWood("Cut wood");

    Precondition prepWood;
    prepWood.Condition = [](const World* w) -> bool {
        return w->GetVillagerCount() > 0;
    };
    CutWood.AddPrecondition(&prepWood);

    CutWood.Action = ActionCutWood;

    CutWood.SetCost(1);

    // Iron state
    States MineIron(" Mine iron");

    Precondition prepIron;
    prepIron.Condition = [](const World* w) -> bool {
        return w->GetVillagerCount() > 0;
    };
    MineIron.AddPrecondition(&prepIron);

    MineIron.Action = ActionMineIron;

    MineIron.SetCost(2);

    // Gold state
    States MineGold("Mine Gold");

    Precondition prepGold;
    prepGold.Condition = [](const World* w) -> bool {
        return w->GetVillagerCount() > 0;
    };
    MineGold.AddPrecondition(&prepGold);

    MineGold.Action = ActionMineGold;

    MineGold.SetCost(2);

    // Farm state
    States CreateFarm("Create Farm");

    Precondition prepFarm;
    prepFarm.Condition = [](const World* w) -> bool {
        return w->GetVillagerCount() > 0 && w->GetWoodCount() > 4;
    };
    CreateFarm.AddPrecondition(&prepFarm);

    CreateFarm.Action = ActionCreateFarm;

    CreateFarm.SetCost(2);

    // Bread state
    States CreateBread("Create Bread");

    Precondition prepBread;
    prepBread.Condition = [](const World* w) -> bool {
        return w->GetVillagerCount() > 0 && w->GetFarmCount() > 0;
    };
    CreateBread.AddPrecondition(&prepBread);

    CreateBread.Action = ActionCreateBread;

    CreateBread.SetCost(2);

    // Warrior state
    States CreateWarrior("Create Warrior");

    Precondition prepWarrior;
    prepWarrior.Condition = [](const World* w) -> bool {
        return w->GetIronCount() > 0 && w->GetGoldCount() > 0 && w->GetBreadCount() > 0;
    };
    CreateWarrior.AddPrecondition(&prepWarrior);

    CreateWarrior.Action = ActionCreateWarrior;

    CreateWarrior.SetCost(5);

    // Attack state
    States AttackEnemy("Attack Enemy");

    Precondition prepAttack;
    prepAttack.Condition = [](const World* w) -> bool {
        bool b = w->GetEnemyFound() && w->GetWarriorCount() >= 10;
        return b;
    };
    AttackEnemy.AddPrecondition(&prepAttack);

    AttackEnemy.Action = ActionAttackEnemy;

    AttackEnemy.SetCost(10);

    // LookForEnemy state
    States LookForEnemy("Look for Enemy");

    Precondition prepLookForEnemy;
    prepLookForEnemy.Condition = [](const World* w) -> bool {
        return (w->GetWarriorCount() > 0 || w->GetVillagerCount() > 0);
    };
    LookForEnemy.AddPrecondition(&prepLookForEnemy);

    LookForEnemy.Action = ActionLookForEnemy;

    LookForEnemy.SetCost(5);

    LookForEnemy.SetOnce();


    std::vector<States*> possibility;

    possibility.push_back(&CreateBread);
    possibility.push_back(&LookForEnemy);
    possibility.push_back(&CreateWarrior);
    possibility.push_back(&MineGold);

   

    #pragma endregion 

	World world = World();
    GoapMachine gp(possibility,&world);
    world.SetWarriorCount(2);
    world.SetVillagerCount(10);
    world.SetIronCount(100);
    world.SetBreadCount(100);
    Node* idx = gp.Execute(&AttackEnemy);

	std::cout << " Bread : " << world.GetBreadCount() << std::endl;
	std::cout << " Villager : " << world.GetVillagerCount() << std::endl;
	std::cout << " Warrior : " << world.GetWarriorCount() << std::endl;
	std::cout << " Gold : " << world.GetGoldCount() << std::endl;
	
    while (idx != nullptr) {
        std::cout << idx->GetState()->GetLabel() << std::endl;
        idx = idx->GetPrev();
    }




    return 0;
}
