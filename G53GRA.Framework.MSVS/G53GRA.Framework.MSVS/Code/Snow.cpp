#include "Snow.h"
#define SIZE 300.0f
Snow::Snow()
{
	snowNumber = 3000;
	glEnable(GL_TEXTURE_2D);
	snows = (snowPiece*)malloc(sizeof(snowPiece) * snowNumber);
	InitialSnow();
}

Snow::~Snow()
{
	free(snows);
	glDisable(GL_TEXTURE_2D);
}

void Snow::Display()
{
	
	for (int i = 0; i < snowNumber; i++)
		{

			glPushMatrix();
			glTranslatef(snows[i].x, snows[i].y, snows[i].z);
			glColor3f(snows[i].r, snows[i].g, snows[i].b);
			glutSolidSphere(snows[i].size, 10, 10);

			glPopMatrix();
		}
	
	


}

void Snow::Update(const double& deltaTime)
{
	for (int i = 0; i < snowNumber; i++)
	{
		snows[i].x += snows[i].vx * deltaTime;
		snows[i].y -= snows[i].vy * deltaTime;
		snows[i].z += snows[i].vz * deltaTime;
		if (snows[i].y <= -30)
		{
			snows[i].x = rand() % 4000 - 500;
			snows[i].y = Scene::GetWindowHeight();
			snows[i].z = rand() % 4000 - 500;
		}
	}
}

void Snow::InitialSnow()
{
	
	
	
	for (int i = 0; i < snowNumber; i++)
	{
		z = rand() % 4000 - 500;
		x = rand() % 4000 - 500;
		y = rand() % Scene::GetWindowHeight();
		snows[i].x = x;
		snows[i].y = y;
		snows[i].z = z;
		snows[i].vx = rand() % 30 * 0.1 - 1.5;
		//snows[i].vx = 0;
		snows[i].vy = rand() % 100000 * 0.001 + 1;
		snows[i].vz = rand() % 30 * 0.1 - 1.5;
		//snows[i].vz = 0;
		snows[i].r = 0.99f + rand() % 1000 * 0.001;
		snows[i].g = 0.99f + rand() % 1000 * 0.001;
		snows[i].b = 0.99f + rand() % 1000 * 0.001;

		snows[i].size = rand() % 100 * 0.01 + 0.5;
	}
}

