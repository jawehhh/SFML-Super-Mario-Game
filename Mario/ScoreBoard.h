#pragma once
#include "Common.h"
class ScoreBoard {
private:
    int score;
    int lives;
    Font font;
    Text scoreText;
    Text livesText;

public:
    ScoreBoard();  // Constructor with default values
    void setScore(int score);
    void setLives(int lives);
    int getScore();
    int getLives();
    void draw(RenderWindow* window);


};