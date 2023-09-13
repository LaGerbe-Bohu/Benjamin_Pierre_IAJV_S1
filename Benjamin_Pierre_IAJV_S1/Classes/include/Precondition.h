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
	Bread,
	Attack,
	Look
};

class Precondition
{
	TypeState state;
	int multiplicateur;

	public :
	Precondition(TypeState myTypeState, int myMultiplicateur) :state(myTypeState), multiplicateur(myMultiplicateur) {};

	int getMultiplicateur() const {
		return multiplicateur;
	}

	bool(*Condition)(const World* world,const Precondition* prep );
};
