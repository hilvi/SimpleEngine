#include "Component.h"

#pragma once
class Wall : public Component
{
public:
    Wall(std::string name, float width, float height);
    void init();
    ~Wall(void);
};

