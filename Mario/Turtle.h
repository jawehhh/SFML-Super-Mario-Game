#pragma once
#pragma once

#include "Common.h"
#include "Object.h"


class Turtle : public Object {
public:

	enum MoveDirection
	{
		RIGHT,
		LEFT,
		//UP,
		JUMPRIGHT,
		JUMPLEFT,
		STOP

	};
	int state = 1;
	float vx = 30.8f;
	float vy = 250.8f;
	float r_vx = -30.8f;


	Turtle();
	void move();
	void fall();
	void jump(bool down) override;
	void setPosition(Vector2f pos);
	void draw(RenderWindow* window);


};
