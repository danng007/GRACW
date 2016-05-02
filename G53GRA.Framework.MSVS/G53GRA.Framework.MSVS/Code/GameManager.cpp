#include "GameManager.h"
using namespace std;
/*
This class used to check game states.
Also used to control flashlight
*/
GameManager::GameManager()
{
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
		//Controled by player's coordinate,  first one is the position of clothese case, second one is the position of tree
		if (pos[0] >= 950.0f && pos[0] <= 1100.0f && pos[2] >= 1000.0f && pos[2] <= 1100.0f) 
		{
			gameState = false;
			currentCamera->Reset(); 
			currentCamera->SetState(false);
		}
	}
	else
	{
		if (pos[0] >= 1950.0f && pos[0] <= 2050.0f && pos[2] >= 1950.0f && pos[2] <= 2050.0f)
		{
			gameState = true;
			currentCamera->Reset(); // reset camera incase translated to outside
			currentCamera->SetState(true);
		}
	}

}

void GameManager::HandleKey(unsigned char key, int state, int x, int y)
{
	if (key == 't' && state == 0)
	{
		lightOn = !lightOn;
	}
}

