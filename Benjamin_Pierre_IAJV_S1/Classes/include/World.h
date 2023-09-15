#ifndef BENJAMIN_PIERRE_IAJV_S1_WORLD_H
#define BENJAMIN_PIERRE_IAJV_S1_WORLD_H

class World {
    private:
        // Living things
        int villagerCount;
        int warriorCount;
        int pristCount;
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
              int myEnemyLivesCount = 10, int myBreadCount = 0, int myIronCount = 0,
              int myGoldCount = 0, int myWoodCount = 0, int myFarmCount = 0,
              bool myEnemyFound = false);

        World(World* myWorld) {
            this->breadCount = myWorld->breadCount;
            this->enemyLivesCount = myWorld->enemyLivesCount;
            this->farmCount = myWorld->farmCount;
            this->villagerCount = myWorld->villagerCount;
            this->warriorCount = myWorld->warriorCount;
            this->enemyFound = myWorld->enemyFound;
            this->goldCount = myWorld->goldCount;
            this->woodCount = myWorld->woodCount;
            this->ironCount = myWorld->ironCount;
        }



        World& operator=(const World* myWorld) {
            this->breadCount = myWorld->breadCount;
            this->enemyLivesCount = myWorld->enemyLivesCount;
            this->farmCount = myWorld->farmCount;
            this->villagerCount = myWorld->villagerCount;
            this->warriorCount = myWorld->warriorCount;
            this->enemyLivesCount = myWorld->enemyLivesCount;
            this->enemyFound = myWorld->enemyFound;
            this->goldCount = myWorld->goldCount;
            this->ironCount = myWorld->ironCount;
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
        int GetPrist() const;
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
        void SetPristCount(int myPristCount);
        void SetStoneCount(int myStoneCount);
        void SetChurchCount(int myChurchCount);
};

#endif //BENJAMIN_PIERRE_IAJV_S1_WORLD_H
