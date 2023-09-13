#include <iostream>

#include "../include/States.h"
#include "../include/World.h"
#include "../include/GoapMachines.h"
#include "../include/Node.h"

// Actions that can be used by the GOAP

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

int main()
{
    #pragma region StatesInit

    // Villager state --------------
    States CreateVillager("Villager created.",Villager,1);
    Precondition prepVillager(Villager,1);
    prepVillager.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetBreadCount() >= prep->getMultiplicateur();
    };

    CreateVillager.Action = ActionCreateVillager;

    // Wood state -------------------
    States CutWood("Cut wood",Wood,2);
    Precondition prepWood(Wood,1);
    prepWood.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->getMultiplicateur();
    };

    CutWood.Action = ActionCutWood;

    // Iron state ---------------
    States MineIron("Mine iron",Iron,2);
    Precondition prepIron(Iron,1);
    prepIron.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->getMultiplicateur();
    };

    MineIron.Action = ActionMineIron;

    // Gold state ---------------
    States MineGold("Mine Gold",Gold,2);
    Precondition prepGold(Gold,1);
    prepGold.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetVillagerCount() >= prep->getMultiplicateur();
    };

    MineGold.Action = ActionMineGold;

    // Farm state ---------------
    States CreateFarm("Create Farm",Farm,3);
    Precondition prepFarm(Farm, 1);
    prepFarm.Condition = [](const World* w,const Precondition * prep) -> bool {
        return w->GetVillagerCount() >= prep->getMultiplicateur();
    };
    Precondition prepFarmWood(Farm, 5);
    prepFarmWood.Condition = [](const World* w, const Precondition* prep) -> bool {
        return w->GetWoodCount() >= prep->getMultiplicateur();
    };

    CreateFarm.Action = ActionCreateFarm;

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

    CreateBread.Action = ActionCreateBread;

    // Warrior state --------------------
    States CreateWarrior("Create Warrior", Warrior, 5);
    Precondition prepWarriorIron(Warrior, 1);
    prepWarriorIron.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetIronCount() >= prep->getMultiplicateur();
    };
    Precondition prepWarriorGold(Warrior, 1);
    prepWarriorGold.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetGoldCount() >= prep->getMultiplicateur();
    };
    Precondition prepWarriorBread(Warrior, 1);
    prepWarriorBread.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetBreadCount() >= prep->getMultiplicateur();
    };

    CreateWarrior.Action = ActionCreateWarrior;

    // Attack state --------------------
    States AttackEnemy("Attack Enemy", Attack, 10);
    Precondition prepAttackLook(Attack, 1);
    prepAttackLook.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetEnemyFound();
    };
    Precondition prepAttackWarriors(Attack, 10);
    prepAttackWarriors.Condition = [](const World* w,const Precondition* prep) -> bool {
        return w->GetWarriorCount() >= prep->getMultiplicateur() || w->GetVillagerCount() >= prep->getMultiplicateur();
    };

    AttackEnemy.Action = ActionAttackEnemy;

    // LookForEnemy state --------------------
    States LookForEnemy("Look for Enemy", Look, 5);
    Precondition prepLookForEnemy(Look, 1);

    prepLookForEnemy.Condition = [](const World* w,const Precondition* prep) -> bool {
        return (w->GetWarriorCount() > 0 || w->GetVillagerCount() > 0);
    };

    LookForEnemy.Action = ActionLookForEnemy;

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

    std::vector<States*> createVillagerS;
    createVillagerS.push_back(&CreateBread);
    std::pair<TypeState, std::vector<States*>> pV(Villager,createVillagerS);
    createVillagerS = std::vector<States*>();
    gp.GetEffectMap().insert(pV);

    std::vector<States*> cutWoodS;
    cutWoodS.push_back(&CreateVillager);
    std::pair<TypeState, std::vector<States*>> pW(Wood,cutWoodS);
    cutWoodS = std::vector<States*>();
    gp.GetEffectMap().insert(pW);

    std::vector<States*> mineIronS;
    mineIronS.push_back(&CreateVillager);
    std::pair<TypeState, std::vector<States*>> pI(Iron,mineIronS);
    mineIronS = std::vector<States*>();
    gp.GetEffectMap().insert(pI);

    std::vector<States*> mineGoldS;
    mineGoldS.push_back(&CreateVillager);
    std::pair<TypeState, std::vector<States*>> pG(Gold,mineGoldS);
    mineGoldS = std::vector<States*>();
    gp.GetEffectMap().insert(pG);

    std::vector<States*> createFarmS;
    createFarmS.push_back(&CreateVillager);
    createFarmS.push_back(&CutWood);
    createFarmS.push_back(&CutWood);
    createFarmS.push_back(&CutWood);
    createFarmS.push_back(&CutWood);
    createFarmS.push_back(&CutWood);
    std::pair<TypeState, std::vector<States*>> pF(Farm,createFarmS);
    createFarmS = std::vector<States*>();
    gp.GetEffectMap().insert(pF);

    std::vector<States*> createBreadS;
    createBreadS.push_back(&CreateFarm);
    createBreadS.push_back(&CreateVillager);
    std::pair<TypeState, std::vector<States*>> pB(Bread,createBreadS);
    createBreadS = std::vector<States*>();
    gp.GetEffectMap().insert(pB);

    std::vector<States*> createWarriorS;
    createWarriorS.push_back(&MineIron);
    createWarriorS.push_back(&MineGold);
    createWarriorS.push_back(&CreateBread);
    std::pair<TypeState, std::vector<States*>> pWa(Warrior,createWarriorS);
    createWarriorS = std::vector<States*>();
    gp.GetEffectMap().insert(pWa);

    std::vector<States*> attackEnemyS;
    attackEnemyS.push_back(&LookForEnemy);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    attackEnemyS.push_back(&CreateWarrior);
    std::pair<TypeState, std::vector<States*>> pA(Attack,attackEnemyS);
    attackEnemyS = std::vector<States*>();
    gp.GetEffectMap().insert(pA);

    std::vector<States*> lookForEnemyS;
    lookForEnemyS.push_back(&CreateVillager);
    std::pair<TypeState, std::vector<States*>> pL(Bread,lookForEnemyS);
    lookForEnemyS = std::vector<States*>();
    gp.GetEffectMap().insert(pL);

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
