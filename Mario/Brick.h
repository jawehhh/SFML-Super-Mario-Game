#pragma once
#include "Common.h"
#include "Object.h"


class Brick : public Object {
public:
	Brick();
	void jump(bool down) override;

};
