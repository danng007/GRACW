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
	currentCamera->GetViewDirection(rotation[0], rotation[1], rotation[2]);
	pos[0] += rotation[0] * 200.0f;
	pos[2] += rotation[2] * 200.0f;
	
	if (gameState)
	{
		if (pos[0] >= 950.0f && pos[0] <= 1100.0f && pos[2] >= 1000.0f && pos[2] <= 1100.0f)
		{
			gameState = false;
			currentCamera->Reset();
			currentCamera->SetState(false);
			cout << "True->false" << endl;
		}
	}
	else
	{
		if (pos[0] >= 1950.0f && pos[0] <= 2050.0f && pos[2] >= 1950.0f && pos[2] <= 2050.0f)
		{
			gameState = true;
			currentCamera->Reset();
			currentCamera->SetState(true);
			cout << "False -> true" << endl;
		}
	}

}
