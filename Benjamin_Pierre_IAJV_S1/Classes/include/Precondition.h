#pragma once
#include <vector>
#include <string>

class World;

enum TypeState {
	Wood,
	Villager,
	Iron,
	Gold,
	Warrior,
	Farm,
	BreadFarm,
	BreadVillager,
	WarriorIron,
	WarriorGold,
	WarriorBread,
	AttackLook,
	AttackWarrior,
	Attack,
	LookCreateWarrior,
	FarmVillager,
	FarmWood,
	VillagerBread,
	Stone,
	ChurchWood,
	ChurchPriest,
	ChurchStone,
	WineParty,
	WineVillager,
	PriestParty,
	PartyGold,
	PartyVillagoies,
	WineWood,
	PriestGold,
	PartyWine,
	AttackChurch
};

class Precondition
{
    private:
        TypeState state;
        int multiplicator;

	public :
        Precondition(TypeState myTypeState, int myMultiplicateur) : state(myTypeState), multiplicator(myMultiplicateur) {};

        int GetMultiplicateur() const {
            return multiplicator;
        }

		TypeState GetTypeState() {
			return state;
		}

        bool(*Condition)(const World* world,const Precondition* prep );
};
