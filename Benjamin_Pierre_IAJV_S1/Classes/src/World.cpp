//
// Created by pierr on 11-Sep-23.
//

#include "../include/World.h"
#include "cassert"

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
    if (myVillagerCount > 0){
        villagerCount = myVillagerCount;
    }
}

void World::SetWarriorCount(unsigned int myWarriorCount) {
    if (myWarriorCount > 0){
        warriorCount = myWarriorCount;
    }
}

void World::SetEnemyLivesCount(unsigned int myEnemyLivesCount) {
    if (myEnemyLivesCount > 0){
        enemyLivesCount = myEnemyLivesCount;
    }
}

void World::SetBreadCount(int myBreadCount) {
    assert(myBreadCount > 0);
    if (myBreadCount > 0){
        breadCount = myBreadCount;
    }
}

void World::SetIronCount(unsigned int myIronCount) {
    if (myIronCount > 0){
        ironCount = myIronCount;
    }
}

void World::SetGoldCount(unsigned int myGoldCount) {
    if (myGoldCount > 0){
        goldCount = myGoldCount;
    }
}

void World::SetWoodCount(unsigned int myWoodCount) {
    if (myWoodCount > 0){
        woodCount = myWoodCount;
    }
}

void World::SetFarmCount(unsigned int myFarmCount) {
    if (myFarmCount > 0){
        farmCount = myFarmCount;
    }
}
