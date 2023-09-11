//
// Created by pierr on 11-Sep-23.
//

#include "../include/World.h"

World::World(unsigned int myVillagerCount, unsigned int myWarriorCount, unsigned int myEnemyLivesCount,
             unsigned int myBreadCount, unsigned int myIronCount, unsigned int myGoldCount,
             unsigned int myWoodCount, unsigned int myFarmCount) {
    villagerCount = myVillagerCount;
    warriorCount = myWarriorCount;
    enemyLivesCount = myEnemyLivesCount;
    breadCount = myBreadCount;
    ironCount = myIronCount;
    goldCount = myGoldCount;
    woodCount = myWoodCount;
    farmCount = myFarmCount;
}

unsigned int World::GetVillagerCount() const {
    return villagerCount;
}

unsigned int World::GetWarriorCount() const {
    return warriorCount;
}

unsigned int World::GetEnemyLivesCount() const {
    return enemyLivesCount;
}

unsigned int World::GetBreadCount() const {
    return breadCount;
}

unsigned int World::GetIronCount() const {
    return ironCount;
}

unsigned int World::GetGoldCount() const {
    return goldCount;
}

unsigned int World::GetWoodCount() const {
    return woodCount;
}

unsigned int World::GetFarmCount() const {
    return farmCount;
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
