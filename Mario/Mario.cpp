#include "Mario.h"



Mario::Mario()
{
	char path[64];
	for (int i = 0; i < 13; i++)
	{
		sprintf(path, "../assets/mario%d.png", i+1);
		textures[i].loadFromFile(path);
	}
	state = 1;
	sprite.setTexture(textures[state-1]);
}

void Mario::setPosition(Vector2f pos)
{
	sprite.setPosition(pos);
}


void Mario::move(MoveDirection dir)
{
	cout << "Move" << endl;
	sprite.setTexture(textures[state-1]);//setting texture wrt to state
	float acc = 4.0f;//acceleration for right or left jump
	switch (state)
	{
	case 1:
		if(dir==RIGHT)
		{
			sprite.move(Vector2f(vx,0));
			state = 12;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc * vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc * vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 2;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else
		{
			state = 1;
		}
		break;
	case 2:
		if (dir == RIGHT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 12;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc * vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc * vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{	
			sprite.move(Vector2f(-vx, 0));
			state = 3;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else
		{
			state = 1;
		}
		break;
	case 3:
		if (dir == RIGHT)
		{
			sprite.move(Vector2f(vx, 0));
			state = 12;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc * vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc * vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 4;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else 
		{
			state = 1;
		}
		break;
	case 4:
		if (dir == RIGHT)
		{
			sprite.move(Vector2f(vx, 0));
			state = 12;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc * vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc * vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 2;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else
		{
			state = 1;
		}
		break;
	case 5:
		state=1;
		if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		break;
	case 6:
		state = 1;
		if (dir == DOWN)
		{
		sprite.move(Vector2f(0, vy));
		state = 7;
		}
		break;
	case 7:
		state = 7;
		break;
	case 8:
		if (dir == RIGHT)
		{
			sprite.move(Vector2f(vx, 0));
			state = 9;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc * vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc * vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 5;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else
		{
			state = 8;
		}
		break;
	case 9:
		if (dir == RIGHT)
		{
			sprite.move(Vector2f(vx, 0));
			state = 10;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc * vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc * vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 5;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else
		{
			state = 8;
		}
		break;
	case 10:
		if (dir == RIGHT)
		{
			sprite.move(Vector2f(vx, 0));
			state = 11;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc * vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc * vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 5;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else
		{
			state = 8;
		}
		break;
	case 11:
		if (dir == RIGHT)
		{
			sprite.move(Vector2f(vx, 0));
			state = 9;
		}
		else if (dir == JUMPLEFT)
		{
			sprite.move(Vector2f(-acc*vx, 0));
			state = 6;
		}
		else if (dir == JUMPRIGHT)
		{
			sprite.move(Vector2f(+acc*vx, 0));
			state = 13;
		}
		else if (dir == LEFT)
		{
			sprite.move(Vector2f(-vx, 0));
			state = 5;
		}
		else if (dir == DOWN)
		{
			sprite.move(Vector2f(0, vy));
			state = 7;
		}
		else
		{
			state = 8;
		}
		break;
	case 12:
		state = 8;
		if (dir == DOWN)
		{
		sprite.move(Vector2f(0, vy));
		state = 7;
		}
		break;
	case 13:
		state = 8;
		if (dir == DOWN)
		{
		sprite.move(Vector2f(0, vy));
		state = 7;
		}
		break;
	

}}

/*void Mario::fall()
{
	pos=sprite.getPosition();
	if (pos.y<=500)
	{
		pos.y += 50;
		sprite.setPosition(pos.x, pos.y);
	}
}*/


void Mario::jump(bool down) {
	// Set vertical speed based on whether Mario is jumping up or down
	cout << vy << endl;
	pos = sprite.getPosition();
	if (fallstate == 1 && down)//if fallstate equals to 1 and not pressing up, setting to speed zero
	{
		vy = 0;
		//pos.y = 515;//wrt to floor position
		counter = 0;//counting jumping before landing, mario cannot jump again
	}
	else if (counter==0&&!down)
	{
		vy = -160;
		counter = 1;
		if (pos.y < 0)
		{
			vy = 0;
			pos.y =0;
		}
	}
	
	else if(fallstate==0)
	{
		vy = 160;
		if (pos.y > 515)
		{
			vy = 0;
			pos.y = 515;
		}
	}
	pos.y += vy;
	sprite.setPosition(pos.x, pos.y);
}

void Mario::fall()
{
	pos.y += 200;
	sprite.setPosition(pos.x, pos.y);
}
