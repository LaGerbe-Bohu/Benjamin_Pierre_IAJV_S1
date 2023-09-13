//
// Created by pierr on 11-Sep-23.
//

#include "../include/World.h"

World::World(unsigned int myVillagerCount, unsigned int myWarriorCount, unsigned int myEnemyLivesCount,
             unsigned int myBreadCount, unsigned int myIronCount, unsigned int myGoldCount,
             unsigned int myWoodCount, unsigned int myFarmCount, bool myEnemyFound) {
    villagerCount = myVillagerCount;
    warriorCount = myWarriorCount;
    enemyLivesCount = myEnemyLivesCount;
    breadCount = myBreadCount;
    ironCount = myIronCount;
    goldCount = myGoldCount;
    woodCount = myWoodCount;
    farmCount = myFarmCount;
    enemyFound = myEnemyFound;
}

int World::GetVillagerCount() const {
    return villagerCount;
}

 int World::GetWarriorCount() const {
    return warriorCount;
}

 int World::GetEnemyLivesCount() const {
    return enemyLivesCount;
}

 int World::GetBreadCount() const {
    return breadCount;
}

 int World::GetIronCount() const {
    return ironCount;
}

 int World::GetGoldCount() const {
    return goldCount;
}

 int World::GetWoodCount() const {
    return woodCount;
}

unsigned int World::GetFarmCount() const {
    return farmCount;
}

bool World::GetEnemyFound() const {
    return enemyFound;
}

void World::SetVillagerCount(unsigned int myVillagerCount) {
    villagerCount = myVillagerCount;
}

void World::SetWarriorCount(unsigned int myWarriorCount) {
    warriorCount = myWarriorCount;
}

void World::SetEnemyLivesCount(unsigned int myEnemyLivesCount) {
    enemyLivesCount = myEnemyLivesCount;
}

void World::SetBreadCount(unsigned int myBreadCount) {
    breadCount = myBreadCount;
}

void World::SetIronCount(unsigned int myIronCount) {
    ironCount = myIronCount;
}

void World::SetGoldCount(unsigned int myGoldCount) {
    goldCount = myGoldCount;
}

void World::SetWoodCount(unsigned int myWoodCount) {
    woodCount = myWoodCount;
}

void World::SetFarmCount(unsigned int myFarmCount) {
    farmCount = myFarmCount;
}

void World::SetEnemyFound(bool myEnemyFound) {
    enemyFound = myEnemyFound;
}
