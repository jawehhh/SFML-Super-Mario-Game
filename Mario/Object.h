#pragma once
#include "Common.h"
class Object {
protected: 
    Vector2f pos;
    float ang;
    Object* next;
    Texture textures[13];
    Sprite sprite; 
    Texture backgroundTexture;
    Sprite backgroundSprite;
    friend class Game;
public:
    Object() {
        next = NULL;
    }
    virtual ~Object() {

    }
    void setPosition(Vector2f pos);
    Vector2f getPosition();
    void draw(RenderWindow* window);
    void flip(float ang);
    virtual void jump(bool down) = 0; // Abstract method
    FloatRect getGlobalBounds() const;
    bool collidesWith(const Object& other);


    
};
