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
	myWorld->SetVillagerCount(myWorld->GetVillagerCount() + 10);
	myWorld->SetBreadCount(myWorld->GetBreadCount() - 10);
}


void ActionCutWood(World* myWorld) {
    myWorld->SetWoodCount(myWorld->GetWoodCount() + 1);
}

void ActionMineIron(World* myWorld) {
    myWorld->SetIronCount(myWorld->GetIronCount() + 10);
}

void ActionMineGold(World* myWorld) {
    myWorld->SetGoldCount(myWorld->GetGoldCount() + 10);
}

void ActionCreateFarm(World* myWorld) {
    myWorld->SetFarmCount(myWorld->GetFarmCount() + 1);
}

void ActionCreateBread(World* myWorld) {
    myWorld->SetBreadCount(myWorld->GetBreadCount() + 1);
}

void ActionCreateWarrior(World* myWorld) {
    myWorld->SetWarriorCount(myWorld->GetWarriorCount() + 10);
    myWorld->SetGoldCount(myWorld->GetGoldCount() - 10);
    myWorld->SetIronCount(myWorld->GetIronCount() - 10);
}

void ActionAttackEnemy(World* myWorld) {
    myWorld->SetEnemyLivesCount(myWorld->GetEnemyLivesCount() - 10);
    myWorld->SetWarriorCount(myWorld->GetWarriorCount() - 10);
}

void ActionLookForEnemy(World* myWorld) {
    myWorld->SetEnemyFound(true);
}

void InitStates() {
    
}

int main()
{
	//InitStates();


    
    #pragma region StatesInit

    // Villager state --------------
    States CreateVillager("Create a villager",Villager,1);
    Precondition prepVillager(Villager,1);
    prepVillager.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetBreadCount() >= prep->getMultiplicateur();
    };

    // Wood state -------------------
    States CutWood("Cut wood",Wood,2);
    Precondition prepWood(Wood,1);
    prepWood.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->getMultiplicateur();
    };

    // Iron state ---------------
    States MineIron("Mine iron",Iron,2);
    Precondition prepIron(Iron,1);
    prepIron.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() > prep->getMultiplicateur();
    };

    // Gold state ---------------
    States MineGold("Mine Gold",Gold,2);
    Precondition prepGold(Gold,2);
    prepGold.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() > prep->getMultiplicateur();
    };
    
    // Farm state ---------------
    States CreateFarm("Create Farm",Farm,3);
    Precondition prepFarmWood(Farm, 1);
    prepFarmWood.Condition = [](const World* w,const Precondition * prep) -> bool {
        return w->GetVillagerCount() > prep->getMultiplicateur();
    };

    Precondition prepFarmWood(Farm, 5);
    prepFarmWood.Condition = [](const World* w, const Precondition* prep) -> bool {
        return w->GetWoodCount() > prep->getMultiplicateur();
    };

    // Bread state --------------------
    States CreateBread("Create Bread",Bread,2);
    Precondition prepBreadVillager(Bread,1);
    prepBreadVillager.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->getMultiplicateur();
    };

    Precondition prepBreadFarm(Bread, 1);
    prepBreadFarm.Condition = [](const World* w, const Precondition* prep) -> bool {
        return  w->GetFarmCount() > prep->getMultiplicateur();
    };

    // Warrior state
    States CreateWarrior("Create Warrior");

    Precondition prepWarrior;
    prepWarrior.Condition = [](const World* w) -> bool {
        bool b = w->GetIronCount() > 0 && w->GetGoldCount() > 0;
        return b;
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

    possibility.push_back(&LookForEnemy);
    possibility.push_back(&CreateVillager);
    possibility.push_back(&CreateWarrior);
    possibility.push_back(&MineIron);
    possibility.push_back(&MineGold);

    #pragma endregion 

	World world = World();
    GoapMachine gp(possibility,&world);
    world.SetWarriorCount(0);
    world.SetBreadCount(10);
    Node* idx = gp.Execute(&AttackEnemy);

	std::cout << " Bread : " << world.GetBreadCount() << std::endl;
	std::cout << " Villager : " << world.GetVillagerCount() << std::endl;
	std::cout << " Warrior : " << world.GetWarriorCount() << std::endl;
	std::cout << " Gold : " << world.GetGoldCount() << std::endl;
	std::cout << " Iron : " << world.GetIronCount() << std::endl;
	std::cout << " Wood : " << world.GetWoodCount() << std::endl;
    std::cout << std::endl;

    while (idx != nullptr) {
        std::cout << idx->GetState()->GetLabel() << std::endl;
        idx = idx->GetPrev();
    }


    return 0;
}
