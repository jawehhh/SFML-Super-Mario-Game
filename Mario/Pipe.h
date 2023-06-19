#pragma once
#pragma once
#include "Common.h"
#include "Object.h"


class Pipe : public Object {
public:
	Pipe();
	void jump(bool down) override;

};
