#pragma once
#include "Common.h"
#include "Object.h"




class Mario: public Object
{
public:
	enum MoveDirection
	{
		RIGHT,
		LEFT,
		DOWN,
		JUMPRIGHT,
		JUMPLEFT,
		STOP

	};
	int state=1;
	float vx = 30.8f;
	float vy;
	int fallstate;
	int counter;
	Mario();
	friend class Game;
	void jump(bool down) override;
	void move(MoveDirection dir);
	void setSpeedy(int s) { fallstate = s; }// to send onFloor response
	void fall(void);
	void setPosition(Vector2f pos);
	

};

 