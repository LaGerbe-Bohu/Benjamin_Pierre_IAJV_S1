#ifndef BENJAMIN_PIERRE_IAJV_S1_WORLD_H
#define BENJAMIN_PIERRE_IAJV_S1_WORLD_H

class World {
    private:
        // Living things
        unsigned int villagerCount;
        unsigned int warriorCount;
        unsigned int enemyLivesCount;
        bool enemyFound;

        // Ressources
        unsigned int breadCount;
        unsigned int ironCount;
        unsigned int goldCount;
        unsigned int woodCount;

        // Buildings
        unsigned int farmCount;

    public:
        // Default constructor
        explicit World(unsigned int myVillagerCount = 0, unsigned int myWarriorCount = 0,
              unsigned int myEnemyLivesCount = 10, unsigned int myBreadCount = 0, unsigned int myIronCount = 0,
              unsigned int myGoldCount = 0, unsigned int myWoodCount = 0, unsigned int myFarmCount = 0,
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
        unsigned int GetVillagerCount() const;
        unsigned int GetWarriorCount() const;
        unsigned int GetEnemyLivesCount() const;
        unsigned int GetBreadCount() const;
        unsigned int GetIronCount() const;
        unsigned int GetGoldCount() const;
        unsigned int GetWoodCount() const;
        unsigned int GetFarmCount() const;
        bool GetEnemyFound() const;

        // Setters
        void SetVillagerCount(unsigned int villagerCount);
        void SetWarriorCount(unsigned int warriorCount);
        void SetEnemyLivesCount(unsigned int enemyLivesCount);
        void SetBreadCount(unsigned int breadCount);
        void SetIronCount(unsigned int myIronCount);
        void SetGoldCount(unsigned int myGoldCount);
        void SetWoodCount(unsigned int myWoodCount);
        void SetFarmCount(unsigned int myFarmCount);
        void SetEnemyFound(bool myEnemyFound);
};

#endif //BENJAMIN_PIERRE_IAJV_S1_WORLD_H
