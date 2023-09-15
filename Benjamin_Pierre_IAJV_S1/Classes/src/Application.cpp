#include <iostream>
#include <iomanip>

#include "../include/States.h"
#include "../include/World.h"
#include "../include/GoapMachines.h"

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
    myWorld->SetIronCount(myWorld->GetIronCount() - 1);
}

void ActionAttackEnemy(World* myWorld) {
    myWorld->SetEnemyLivesCount(myWorld->GetEnemyLivesCount() - 1);
    myWorld->SetWarriorCount(myWorld->GetWarriorCount() - 1);
}

void ActionLookForEnemy(World* myWorld) {
    myWorld->SetEnemyFound(true);
}

void InitStates() {

}

int main()
{
    clock_t start, end;

	//InitStates();

    #pragma region StatesInit

    // Villager state --------------
    States CreateVillager("Villager created.",Villager,3);
    Precondition prepVillager(Villager,1);
    prepVillager.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetBreadCount() >= prep->GetMultiplicateur();
    };

    CreateVillager.Action = ActionCreateVillager;
    CreateVillager.AddToVecPrecondition(&prepVillager);


    // Wood state -------------------
    States CutWood("Cut wood",Wood,2);
    Precondition prepWood(Wood,1);
    prepWood.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->GetMultiplicateur();
    };

    CutWood.Action = ActionCutWood;
    CutWood.AddToVecPrecondition(&prepWood);;

    // Iron state ---------------
    States MineIron("Mine iron",Iron,2);
    Precondition prepIron(Iron,1);
    prepIron.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->GetMultiplicateur();
    };

    MineIron.Action = ActionMineIron;
    MineIron.AddToVecPrecondition(&prepIron);;

    // Gold state ---------------
    States MineGold("Mine Gold",Gold,2);
    Precondition prepGold(Gold,1);
    prepGold.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->GetMultiplicateur();
    };

    MineGold.Action = ActionMineGold;
    MineGold.AddToVecPrecondition(&prepGold);


    // Farm state ---------------
    States CreateFarm("Create Farm",Farm,3);
    Precondition prepFarm(FarmVillager, 1);
    prepFarm.Condition = [](const World* w,const Precondition * prep) -> bool {
        return w->GetVillagerCount() >= prep->GetMultiplicateur();
    };
    Precondition prepFarmWood(FarmWood, 1);
    prepFarmWood.Condition = [](const World* w, const Precondition* prep) -> bool {
        return w->GetWoodCount() >= prep->GetMultiplicateur();
    };


    CreateFarm.Action = ActionCreateFarm;
    CreateFarm.AddToVecPrecondition(&prepFarm);
    CreateFarm.AddToVecPrecondition(&prepFarmWood);

    // Bread state --------------------
    States CreateBread("Create Bread",BreadFarm,2);
    Precondition prepBreadVillager(BreadVillager,1);
    prepBreadVillager.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->GetMultiplicateur();
    };
    Precondition prepBreadFarm(BreadFarm, 1);
    prepBreadFarm.Condition = [](const World* w, const Precondition* prep) -> bool {
        return  w->GetFarmCount() >= prep->GetMultiplicateur();
    };

    CreateBread.Action = ActionCreateBread;
    CreateBread.AddToVecPrecondition(&prepBreadFarm);
    CreateBread.AddToVecPrecondition(&prepBreadVillager);
    // Warrior state --------------------
    States CreateWarrior("Create Warrior", Warrior, 5);
    Precondition prepWarriorIron(WarriorIron, 1);
    prepWarriorIron.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetIronCount() >= prep->GetMultiplicateur();
    };
    Precondition prepWarriorGold(WarriorGold, 1);
    prepWarriorGold.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetGoldCount() >= prep->GetMultiplicateur();
    };
    Precondition prepWarriorBread(WarriorBread, 1);
    prepWarriorBread.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetBreadCount() >= prep->GetMultiplicateur();
    };

    CreateWarrior.Action = ActionCreateWarrior;
    CreateWarrior.AddToVecPrecondition(&prepWarriorBread);
    CreateWarrior.AddToVecPrecondition(&prepWarriorGold);
    CreateWarrior.AddToVecPrecondition(&prepWarriorIron);

    // Attack state --------------------
    States AttackEnemy("Attack Enemy", Attack, 10);
    Precondition prepAttackLook(AttackLook, 1);
    prepAttackLook.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetEnemyFound();
    };
    Precondition prepAttackWarriors(AttackWarrior, 1);
    prepAttackWarriors.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetWarriorCount() >= prep->GetMultiplicateur();
    };

    AttackEnemy.Action = ActionAttackEnemy;
    AttackEnemy.AddToVecPrecondition(&prepAttackWarriors);
    AttackEnemy.AddToVecPrecondition(&prepAttackLook);
    // LookForEnemy state --------------------
    States LookForEnemy("Look for Enemy", LookCreateWarrior, 5);
    Precondition prepLookForEnemy(LookCreateWarrior, 1);

    prepLookForEnemy.Condition = [](const World* w,const Precondition* prep) -> bool {
        return (w->GetWarriorCount() > 0);
    };

    LookForEnemy.Action = ActionLookForEnemy;
    LookForEnemy.AddToVecPrecondition(&prepLookForEnemy);
    std::vector<States*> possibility;

    possibility.push_back(&LookForEnemy);
    possibility.push_back(&CreateVillager);
    possibility.push_back(&CreateWarrior);
    possibility.push_back(&MineIron);
    possibility.push_back(&MineGold);
    possibility.push_back(&CutWood);
    possibility.push_back(&CreateBread);
    possibility.push_back(&CreateFarm);

    #pragma endregion

    // World -----------------
	World world = World();
    GoapMachine gp(possibility,&world);
    world.SetVillagerCount(2);

    // Goap machine hash map setup -------------
    gp.AddToHmap(Villager, &CreateBread );
    gp.AddToHmap(Wood,  &CreateVillager );
    gp.AddToHmap(Iron,  &CreateVillager );
    gp.AddToHmap(Gold,  &CreateVillager );
    gp.AddToHmap(BreadFarm,  &CreateFarm);
    gp.AddToHmap(BreadVillager, &CreateVillager);
    gp.AddToHmap(WarriorIron, &MineIron);
    gp.AddToHmap(WarriorGold, &MineGold);
    gp.AddToHmap(WarriorBread, &CreateBread);
    gp.AddToHmap(AttackLook,&LookForEnemy);
    gp.AddToHmap(AttackWarrior, &CreateWarrior);
    gp.AddToHmap(LookCreateWarrior, &CreateWarrior );
    gp.AddToHmap(FarmWood, &CutWood );
    gp.AddToHmap(FarmVillager, &CreateVillager );

    start = clock();
    Node* idx;
    for (int i = 0; i < 1000000; ++i) {
        idx = gp.Execute(&AttackEnemy);
    }
    end = clock();

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


    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
    return 0;
}
