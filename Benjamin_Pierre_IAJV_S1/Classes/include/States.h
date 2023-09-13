#pragma one
#include <vector>
#include "Precondition.h"
class States {
    private:
        unsigned int cost;
        std::vector<Precondition> vecPreconditions;
        std::string label;
        bool once;

    public:
        States(const std::string& myLabel) {
            label = myLabel;
            once = false;
            vecPreconditions = *(new std::vector<Precondition>);
            cost = 0;
        }

        ~States() {
            vecPreconditions.clear();
        }

        std::string GetLabel() const {
            return label;
        }

        void SetOnce() {
            once = true;
        }

        bool GetOnce() const {
            return once;
        }

        void AddPrecondition(const Precondition* precondition) {
            this->vecPreconditions.push_back(*precondition);
        }

        unsigned int GetCost() const {
            return cost;
        }

        int NonMetPreconditions(const World*);

        // /*Fonction de precondition */
        void SetCost(unsigned int myCost) {
            cost = myCost;
        }

        void ( *Action )(World* world){};  // Function pointer to the action
        // /*Fonction de precondition */
};
