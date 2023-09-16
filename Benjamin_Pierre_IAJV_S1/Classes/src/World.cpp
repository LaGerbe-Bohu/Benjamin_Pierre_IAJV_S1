#include "../include/World.h"

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

int World::GetWineCount() const
{
    return wineCount;
}

bool World::GetEnemyFound() const {
    return enemyFound;
}

bool World::GetParty() const
{
    return Party;
}

int World::GetPriest() const
{
    return PriestCount;
}

int World::GetStone() const
{
    return stoneCount;
}

int World::GetChurch() const
{
    return churchCount;
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

void World::SetParty(bool myParty)
{
    this->Party = myParty;
}

void World::SetWineCount(int myWineCount)
{
    this->wineCount = myWineCount;
}

void World::SetPriestCount(int myPriestCount)
{
    PriestCount = myPriestCount;
}

void World::SetStoneCount(int myStoneCount)
{
    stoneCount = myStoneCount;
}

void World::SetChurchCount(int myChurchCount)
{
    churchCount = myChurchCount;
}
