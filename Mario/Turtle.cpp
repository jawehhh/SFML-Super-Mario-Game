#include "Turtle.h"


Turtle::Turtle()
{


	textures[0].loadFromFile("../assets/turtle1.png");
	textures[1].loadFromFile("../assets/turtle2.png");
	textures[2].loadFromFile("../assets/turtle6.png");

	sprite.setTexture(textures[0]);
}

void Turtle::setPosition(Vector2f pos)
{
	sprite.setPosition(pos);
}

void Turtle::draw(RenderWindow* window) {
	window->draw(sprite);
}



void Turtle::move()
{
	//cout << "Move" << endl;
	//sprite.setTexture(textures[1]);











	if (sprite.getPosition().x < 1240) {



		sprite.setTexture(textures[1]);
		// Initialize Turtle's horizontal and vertical speed
		sprite.move(Vector2f(vx, 0));


	}


	else {

		sprite.setTexture(textures[1]);
		setPosition({ 60, 100 });
		sprite.move(Vector2f(r_vx, 0));
	}







}

void Turtle::jump(bool down)
{

}



void Turtle::fall()
{
	pos = sprite.getPosition();
	if (pos.y <= 530)
	{
		pos.y += 50;
		sprite.setPosition(pos.x, pos.y);

	}
}


