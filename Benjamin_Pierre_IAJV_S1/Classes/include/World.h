#ifndef BENJAMIN_PIERRE_IAJV_S1_WORLD_H
#define BENJAMIN_PIERRE_IAJV_S1_WORLD_H

class World {
    private:
        // Living things
        unsigned int villagerCount;
        unsigned int warriorCount;
        unsigned int enemyLivesCount;

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
              unsigned int myGoldCount = 0, unsigned int myWoodCount = 0, unsigned int myFarmCount = 0);

        // Getters
        unsigned int GetVillagerCount() const;
        unsigned int GetWarriorCount() const;
        unsigned int GetEnemyLivesCount() const;
        unsigned int GetBreadCount() const;
        unsigned int GetIronCount() const;
        unsigned int GetGoldCount() const;
        unsigned int GetWoodCount() const;
        unsigned int GetFarmCount() const;

        // Setters
        void SetVillagerCount(unsigned int villagerCount);
        void SetWarriorCount(unsigned int warriorCount);
        void SetEnemyLivesCount(unsigned int enemyLivesCount);
        void SetBreadCount(int breadCount);
        void SetIronCount(unsigned int myIronCount);
        void SetGoldCount(unsigned int myGoldCount);
        void SetWoodCount(unsigned int myWoodCount);
        void SetFarmCount(unsigned int myFarmCount);
};

#endif //BENJAMIN_PIERRE_IAJV_S1_WORLD_H
