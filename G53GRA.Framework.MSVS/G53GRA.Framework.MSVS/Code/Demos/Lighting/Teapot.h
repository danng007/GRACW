#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Teapot :
	public DisplayableObject,
	public Animation
{
public:
	Teapot();
	~Teapot();

	void Display();
	void Update(const double& deltaTime);
};

