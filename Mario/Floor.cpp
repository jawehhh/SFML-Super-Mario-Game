#include "Floor.h"


Floor::Floor() {
	backgroundTexture.loadFromFile("../assets/floor.png");
	backgroundTexture.setRepeated(true);
	sprite.setTexture(backgroundTexture);
	sprite.setTextureRect(IntRect(0,600,1280,99));
	
}

void Floor::jump(bool down)
{

}

