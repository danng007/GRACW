#include "FirstRoom.h"
#define SIZE 300.0f
/*
This class used to draw the room scene. Also used to manage display of castle and skybox.
File input used here so it's more convenient to manage the room's structure.
*/
FirstRoom::FirstRoom(GameManager *gameManager)
{
	glEnable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);
	gm = gameManager;
	glEnable(GL_TEXTURE_2D);
	ReadFile(); 
	clotheseCase = new ClotheseCase();
	drawCube = new DrawCube();
	table = new Table();
	castle = new Castle();
	sky = new SkyBox();
	BindTexture();
}

FirstRoom::~FirstRoom()
{
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
}

void FirstRoom::Display()
{

	if (gm->gameState) // Room stage
	{

		glPushMatrix();
		glTranslatef(0.0f, -100.0f, 0.0f);
		for (int i = 0; i < mapWidth; i++)
		{
			for (int j = 0; j < mapHeight; j++)
			{

				glPushMatrix();
				glTranslatef((i + 0.5) * SIZE, -110.0f, (j + 0.5)* SIZE);
				drawCube->SetTexture(2.0f, 2.0f);
				drawCube->SetTextureID(floorID);
				DrawBox(SIZE, 10.0f, SIZE);
				if (Scene::GetCamera()->projection)
				{
					glTranslatef(0.0f, 310.0f, 0.0f);
					drawCube->SetTexture(1.0f, 1.0f);
					drawCube->SetTextureID(ceillingID);
					DrawBox(SIZE, 10.0f, SIZE);
				}
				drawCube->SetTextureID(0);
				glPopMatrix();

				switch (room[i][j])
				{
				case '0': //blank
					break;
				case '1': //Wall
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, 50.0f, (j + 0.5)* SIZE);
					drawCube->SetTexture(1.0f, 1.0f);
					drawCube->SetTextureID(wallpaperID);
					DrawBox(SIZE, 300.0f, SIZE);
					glPopMatrix();
					break;
				case '2': //Door
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, 0.0f, (j + 0.5)* SIZE);
					drawCube->SetTexture(1.0f, 1.0f);
					drawCube->SetTextureID(doorID);
					DrawBox(70.0f, 200.0f, SIZE);
					glPushMatrix();
					glTranslatef(0.0f, 150.0f, 0.0f);
					drawCube->SetTexture(70.0 / SIZE, 100.0f / SIZE);
					drawCube->SetTextureID(wallpaperID);
					DrawBox(70.0f, 100.0f, SIZE);
					glPopMatrix();
					glTranslatef(-92.5f, 50.0f, 0.0f);
					drawCube->SetTexture(115.0 / SIZE, 1.0f);
					drawCube->SetTextureID(wallpaperID);
					DrawBox(115.0f, 300.0f, SIZE);
					glTranslatef(185.0f, 0.0f, 0.0f);
					DrawBox(115.0f, 300.0f, SIZE);
					glPopMatrix();
					break;
				case '3': //Window
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, 0.0f, (j + 0.5)* SIZE);
					drawCube->SetTexture(1.0f, 1.0f);
					drawCube->SetTextureID(windowID);
					DrawBox(180.0f, 200.0f, SIZE);
					glPushMatrix();
					glTranslatef(0.0f, 150.0f, 0.0f);
					drawCube->SetTexture(180.0 / SIZE, 100.0f / SIZE);
					drawCube->SetTextureID(wallpaperID);
					DrawBox(180.0f, 100.0f, SIZE);
					glPopMatrix();
					glTranslatef(-120.0f, 50.0f, 0.0f);
					drawCube->SetTexture(60.0f / SIZE, 1.0f);
					drawCube->SetTextureID(wallpaperID);
					DrawBox(60.0f, 300.0f, SIZE);
					glTranslatef(240.0f, 0.0f, 0.0f);
					DrawBox(60.0f, 300.0f, SIZE);
					glPopMatrix();
					break;
				case '4': //Clothese Box
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, -100.0f, (j + 0.5) * SIZE);
					glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
					glScalef(1.5f, 1.5f, 1.5f);
					clotheseCase->Display();
					glPopMatrix();
					break;
				case '5': //Table with desk lamp
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, -100.0f, (j + 0.5) * SIZE);
					glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
					glScalef(1.8f, 1.8f, 1.8f);
					table->position((i + 0.5) * SIZE, -100.0f, (j + 0.5) * SIZE);
					table->Display();
					glPopMatrix();
					break;
				case '6': //Bed
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, -100.0f, (j + 0.5) * SIZE);
					glScalef(15.0f, 15.0f, 15.0f);
					bed.RenderModel();
					glPopMatrix();
					break;
				default:
					break;
				}

			}
		}
		drawCube->SetTextureID(0);
		glPopMatrix();
	}
	else //Castle Stage.
	{
		sky->Display();
		castle->Display(); //In room stage, player unable go to outside.
	}
}


void FirstRoom::ReadFile()
{
	int j = 0, k = 0;
	int length;
	myfile.open(fileString);      // open input file  
	string s;
	if (myfile.good()) {
		while (getline(myfile, s)) {
			for (int i = 0; i < s.size(); i++) {
				room[j][k] = s[i];
				cout << s[i];
				k++;
			}
			mapHeight = k;
			k = 0;
			cout << endl;
			j++;
		}
	}
	mapWidth = j;
	myfile.close();
}


void FirstRoom::BindTexture()
{
	bed.LoadOBJ("./texture/gtaBed.obj");
	floorID = Scene::GetTexture("./texture/Floor.bmp");
	ceillingID = Scene::GetTexture("./texture/Ceiling.bmp");
	wallpaperID = Scene::GetTexture("./texture/Wallpaper.bmp");
	doorID = Scene::GetTexture("./texture/RoomDoor.bmp");
	windowID = Scene::GetTexture("./texture/Window.bmp");
}


void FirstRoom::DrawBox(float sx, float sy, float sz)
{
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}
