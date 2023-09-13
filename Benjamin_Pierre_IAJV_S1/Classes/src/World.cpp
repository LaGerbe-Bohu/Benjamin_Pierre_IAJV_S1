#include "../include/World.h"

World::World(int myVillagerCount, int myWarriorCount, int myEnemyLivesCount,
             int myBreadCount, int myIronCount, int myGoldCount,
             int myWoodCount, int myFarmCount, bool myEnemyFound) {
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

int World::GetFarmCount() const {
    return farmCount;
}

bool World::GetEnemyFound() const {
    return enemyFound;
}

void World::SetVillagerCount(int myVillagerCount) {
    villagerCount = myVillagerCount;
}

void World::SetWarriorCount(int myWarriorCount) {
    warriorCount = myWarriorCount;
}

void World::SetEnemyLivesCount(int myEnemyLivesCount) {
    enemyLivesCount = myEnemyLivesCount;
}

void World::SetBreadCount(int myBreadCount) {
    breadCount = myBreadCount;
}

void World::SetIronCount(int myIronCount) {
    ironCount = myIronCount;
}

void World::SetGoldCount(int myGoldCount) {
    goldCount = myGoldCount;
}

void World::SetWoodCount(int myWoodCount) {
    woodCount = myWoodCount;
}

void World::SetFarmCount(int myFarmCount) {
    farmCount = myFarmCount;
}

void World::SetEnemyFound(bool myEnemyFound) {
    enemyFound = myEnemyFound;
}
