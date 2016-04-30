#include "FirstRoom.h"

#define SIZE 300.0f
FirstRoom::FirstRoom(GameManager *gameManager)
{
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
	//glDisable(GL_TEXTURE_2D);
}

void FirstRoom::Display()
{

	

	if (gm->gameState)
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
				glTranslatef(0.0f, 310.0f, 0.0f);
				drawCube->SetTexture(1.0f, 1.0f);
				drawCube->SetTextureID(ceillingID);
				DrawBox(SIZE, 10.0f, SIZE);
				drawCube->SetTextureID(0);
				glPopMatrix();

				switch (room[i][j])
				{
				case '0':
					break;
				case '1':
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, 50.0f, (j + 0.5)* SIZE);
					drawCube->SetTexture(1.0f, 1.0f);
					drawCube->SetTextureID(wallpaperID);
					DrawBox(SIZE, 300.0f, SIZE);
					glPopMatrix();
					break;
				case '2':
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
				case '3':
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
				case '4':
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, -100.0f, (j + 0.5) * SIZE);
					glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
					glScalef(1.5f, 1.5f, 1.5f);
					clotheseCase->Display();
					//cout << (i + 0.5) * SIZE << " " << (j + 0.5) * SIZE << endl;  ->1050
					glPopMatrix();
					break;
				case '5':
					glPushMatrix();
					glTranslatef((i + 0.5) * SIZE, -100.0f, (j + 0.5) * SIZE);
					glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
					glScalef(1.8f, 1.8f, 1.8f);
					table->Display();
					glPopMatrix();
					break;
				case '6':
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
	else
	{
		sky->Display();
		castle->Display();
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
	floorID = Scene::GetTexture("./Floor.bmp");
	ceillingID = Scene::GetTexture("./Ceiling.bmp");
	wallpaperID = Scene::GetTexture("./Wallpaper.bmp");
	doorID = Scene::GetTexture("./RoomDoor.bmp");
	windowID = Scene::GetTexture("./Window.bmp");
}


void FirstRoom::DrawBox(float sx, float sy, float sz)
{
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}