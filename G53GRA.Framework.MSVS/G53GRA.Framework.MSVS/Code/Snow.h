#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "GameManager.h"
class snowPiece{
	public:
		float x, y, z;
		float vx, vy, vz;
		float r, g, b;
		float size;
};


class Snow :
	public DisplayableObject,
	public Animation
{
public:
	Snow(GameManager *gameManager);
	~Snow();

	void Display();
	void InitialSnow();
	void Update(const double& deltaTime);
private:
	GameManager *gm;
	snowPiece* snows;
	int snowNumber;
	int texId;
	float r, g, b;
	float x, y, z;
	float vx, vy;
	float size;
	float positionX, positionY, positionZ;
};

