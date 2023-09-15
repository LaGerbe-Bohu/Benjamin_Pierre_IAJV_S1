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
	FarmWood
};

class Precondition
{
    private:
        TypeState state;
        int multiplicateur;

	public :
        Precondition(TypeState myTypeState, int myMultiplicateur) :state(myTypeState), multiplicateur(myMultiplicateur) {};

        int GetMultiplicateur() const {
            return multiplicateur;
        }

		TypeState GetTypeState() {
			return state;
		}

        bool(*Condition)(const World* world,const Precondition* prep );
};
