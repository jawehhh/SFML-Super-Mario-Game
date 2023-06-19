#pragma once
#include"Common.h"
#include "Object.h"

class GameOver
{
private:
    Font font;
    Text gameOverText;

public:
    GameOver();
    void draw(RenderWindow* window);
};

