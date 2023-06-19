#pragma once
#include "Common.h"
#include "Brick.h"
#include "Floor.h"
#include  "Pipe.h"
#include  "Spipe.h"
#include "Object.h"
#include "Mario.h"
#include "Turtle.h"
#include "ScoreBoard.h"
#include "GameOver.h"


class Game {
protected:
    Texture textures[8];
    Sprite sprite;
    Vector2f pos;
    RenderWindow* window;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Object* Bgobjects;
    Object* objects;
    Brick* addBrick(void);
    Pipe* addPipe(void);
    Spipe* addSpipe(void);
    Floor* addFloor(void);
    Mario* addMario(void);
    Turtle* addTurtle(void);
public:
    friend class Mario;
	Game();
    ~Game();
	void update(void);
	void drawBackground();
    void drawObjects();
	void setPosition(Vector2f pos);
    bool onFloor(Object* obj);
    bool onBrick(Object* obj);
    bool collidesWith(Object* obj);
    bool checkCollision(Turtle* t, Mario* m, int& side);
    void removeObject(Object* obj);
    void handleCollision(void);
    bool handleObjecthit(Mario* mario);

 

};