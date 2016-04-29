#include "GameManager.h"
#include <iostream>
using namespace std;
GameManager::GameManager()
{
	cout << "GameM" << endl;
	glEnable(GL_TEXTURE_2D);
	currentCamera = Scene::GetCamera();
}
GameManager::~GameManager()
{
	glDisable(GL_TEXTURE_2D);
}
void GameManager::Display()
{
	currentCamera->GetEyePosition(pos[0], pos[1], pos[2]);
	if (gameState)
	{
		if (pos[0] >= 950 && pos[0] <= 1150 && pos[2] >= 950 && pos[2] <= 1150)
		{
			gameState = false;
			cout << "True->false" << endl;
		}
	}
	else
	{
		if (pos[0] >= 950 && pos[0] <= 1150 && pos[2] >= 150 && pos[2] <= 250)
		{
			gameState = true;
			cout << "False -> true" << endl;
		}
	}
	if (gameState)
	{
		//cout << pos[0] <<" " <<pos[2] <<" True" << endl;
	}
	else
	{
		//cout << "False" << endl;
	}
}
