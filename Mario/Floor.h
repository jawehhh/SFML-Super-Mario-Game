#pragma once
#include "Common.h"
#include "Object.h"


class Floor : public Object {
public:
	Floor();
	void jump(bool down) override;
};
