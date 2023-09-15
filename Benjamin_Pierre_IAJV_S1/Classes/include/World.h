#ifndef BENJAMIN_PIERRE_IAJV_S1_WORLD_H
#define BENJAMIN_PIERRE_IAJV_S1_WORLD_H

class World {
    private:
        // Living things
        int villagerCount;
        int warriorCount;
        int PriestCount;
        int enemyLivesCount;
        
        bool enemyFound;
        bool Party;


        // Ressources
        int breadCount;
        int ironCount;
        int goldCount;
        int woodCount;
        int wineCount;
        int stoneCount;
        int churchCount;

        // Buildings
        int farmCount;

    public:
        // Default constructor
        explicit World(int myVillagerCount = 0, int myWarriorCount = 0,
            int myPriestCount = 0, int myEnemyLivesCount = 10,
            int myBreadCount = 0, int myIronCount = 0,
            int myGoldCount = 0, int myWoodCount = 0, int myWineCount = 0,
            int myStoneCount = 0, int myChurchCount = 0, int myFarmCount = 0,
            bool myEnemyFound = false, bool myParty = false)
            : villagerCount(myVillagerCount), warriorCount(myWarriorCount),
            PriestCount(myPriestCount), enemyLivesCount(myEnemyLivesCount),
            enemyFound(myEnemyFound), Party(myParty), breadCount(myBreadCount),
            ironCount(myIronCount), goldCount(myGoldCount), woodCount(myWoodCount),
            wineCount(myWineCount), stoneCount(myStoneCount),
            churchCount(myChurchCount), farmCount(myFarmCount) {}

        World(const World* myWorld) {
            this->villagerCount = myWorld->villagerCount;
            this->warriorCount = myWorld->warriorCount;
            this->PriestCount = myWorld->PriestCount;
            this->enemyLivesCount = myWorld->enemyLivesCount;
            this->enemyFound = myWorld->enemyFound;
            this->Party = myWorld->Party;
            this->breadCount = myWorld->breadCount;
            this->ironCount = myWorld->ironCount;
            this->goldCount = myWorld->goldCount;
            this->woodCount = myWorld->woodCount;
            this->wineCount = myWorld->wineCount;
            this->stoneCount = myWorld->stoneCount;
            this->churchCount = myWorld->churchCount;
            this->farmCount = myWorld->farmCount;
        }



        World& operator=(const World* myWorld) {
            this->villagerCount = myWorld->villagerCount;
            this->warriorCount = myWorld->warriorCount;
            this->PriestCount = myWorld->PriestCount;
            this->enemyLivesCount = myWorld->enemyLivesCount;
            this->enemyFound = myWorld->enemyFound;
            this->Party = myWorld->Party;
            this->breadCount = myWorld->breadCount;
            this->ironCount = myWorld->ironCount;
            this->goldCount = myWorld->goldCount;
            this->woodCount = myWorld->woodCount;
            this->wineCount = myWorld->wineCount;
            this->stoneCount = myWorld->stoneCount;
            this->churchCount = myWorld->churchCount;
            this->farmCount = myWorld->farmCount;
            return *this;
        }

        // Getters
        int GetVillagerCount() const;
        int GetWarriorCount() const;
        int GetEnemyLivesCount() const;
        int GetBreadCount() const;
        int GetIronCount() const;
        int GetGoldCount() const;
        int GetWoodCount() const;
        int GetFarmCount() const;
        int GetWineCount() const;
        bool GetEnemyFound() const;
        bool GetParty() const;
        int GetPriest() const;
        int GetStone() const;
        int GetChurch() const;

        // Setters
        void SetVillagerCount(int villagerCount);
        void SetWarriorCount(int warriorCount);
        void SetEnemyLivesCount(int enemyLivesCount);
        void SetBreadCount(int breadCount);
        void SetIronCount(int myIronCount);
        void SetGoldCount(int myGoldCount);
        void SetWoodCount(int myWoodCount);
        void SetFarmCount(int myFarmCount);
        void SetEnemyFound(bool myEnemyFound);
        void SetParty(bool myParty);
        void SetWineCount(int myWineCount);
        void SetPriestCount(int myPriestCount);
        void SetStoneCount(int myStoneCount);
        void SetChurchCount(int myChurchCount);
};

#endif //BENJAMIN_PIERRE_IAJV_S1_WORLD_H
