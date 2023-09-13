#pragma once
#include <vector>
#include <string>

class World;

class Precondition
{
    private:
        std::string label;

    public :
        std::string GetLabel() const {
            return label;
        }

	bool(*Condition)(const World* world);
};
