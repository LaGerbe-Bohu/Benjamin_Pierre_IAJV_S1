// Benjamin_Pierre_IAJV_S1.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "../include/States.h"
#include "../include/Precondition.h"
#include "../include/World.h"


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
    myWorld->SetWoodCount(myWorld->GetWoodCount() - 5);
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
    // Villager state
	States CreateVillager;

    Precondition prepVillager;
    prepVillager.Condition = [](World* w) -> bool {
        return w->GetBreadCount() > 0;
    };
    CreateVillager.AddPrecondition(&prepVillager);

	CreateVillager.Action = ActionCreateVillager;

    CreateVillager.SetCost(1);

    // Wood state
    States CutWood;

    Precondition prepWood;
    prepWood.Condition = [](World* w) -> bool {
        return w->GetVillagerCount() > 0;
    };
    CutWood.AddPrecondition(&prepWood);

    CutWood.Action = ActionCutWood;

    CutWood.SetCost(1);

    // Iron state
    States MineIron;

    Precondition prepIron;
    prepIron.Condition = [](World* w) -> bool {
        return w->GetVillagerCount() > 0;
    };
    MineIron.AddPrecondition(&prepIron);

    MineIron.Action = ActionMineIron;

    MineIron.SetCost(2);

    // Gold state
    States MineGold;

    Precondition prepGold;
    prepGold.Condition = [](World* w) -> bool {
        return w->GetVillagerCount() > 0;
    };
    MineGold.AddPrecondition(&prepGold);

    MineGold.Action = ActionMineGold;

    MineGold.SetCost(2);

    // Farm state
    States CreateFarm;

    Precondition prepFarm;
    prepFarm.Condition = [](World* w) -> bool {
        return w->GetVillagerCount() > 0 && w->GetWoodCount() > 4;
    };
    CreateFarm.AddPrecondition(&prepFarm);

    CreateFarm.Action = ActionCreateFarm;

    CreateFarm.SetCost(2);

    // Bread state
    States CreateBread;

    Precondition prepBread;
    prepBread.Condition = [](World* w) -> bool {
        return w->GetVillagerCount() > 0 && w->GetFarmCount() > 0;
    };
    CreateBread.AddPrecondition(&prepBread);

    CreateBread.Action = ActionCreateBread;

    CreateBread.SetCost(2);

    // Warrior state
    States CreateWarrior;

    Precondition prepWarrior;
    prepWarrior.Condition = [](World* w) -> bool {
        return w->GetIronCount() > 0 && w->GetGoldCount() > 0 && w->GetBreadCount() > 0;
    };
    CreateWarrior.AddPrecondition(&prepWarrior);

    CreateWarrior.Action = ActionCreateWarrior;

    CreateWarrior.SetCost(5);

    // Attack state
    States AttackEnemy;

    Precondition prepAttack;
    prepAttack.Condition = [](World* w) -> bool {
        return w->GetEnemyFound() > 0 && w->GetWarriorCount() > 10;
    };
    AttackEnemy.AddPrecondition(&prepAttack);

    AttackEnemy.Action = ActionAttackEnemy;

    AttackEnemy.SetCost(10);

    // LookForEnemy state
    States LookForEnemy;

    Precondition prepLookForEnemy;
    prepLookForEnemy.Condition = [](World* w) -> bool {
        return w->GetWarriorCount() > 0 || w->GetVillagerCount() > 0;
    };
    LookForEnemy.AddPrecondition(&prepLookForEnemy);

    LookForEnemy.Action = ActionLookForEnemy;

    LookForEnemy.SetCost(5);
}

int main()
{
	InitStates();
	World world = World();
	std::cout << world.GetBreadCount() << " bread" << std::endl;
	world.SetBreadCount(11);
	std::cout << world.GetBreadCount() << " bread" << std::endl;
    return 0;
}
