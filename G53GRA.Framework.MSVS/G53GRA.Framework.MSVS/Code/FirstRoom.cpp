#include "FirstRoom.h"

#define SIZE 300.0f
FirstRoom::FirstRoom()
{
	ReadFile(); 
	clotheseCase = new ClotheseCase();
	drawCube = new DrawCube();
	castle = new Castle();
	table = new Table();
}

FirstRoom::~FirstRoom()
{

}

void FirstRoom::Display()
{


	glDisable(GL_CULL_FACE); 
	glPushMatrix();

	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			switch (room[i][j])
			{
			case '0':
				glColor3f(1.0f, 0.0f, 0.0f);
				DrawSingleFloor(i, j);
				break;
			case '1':
				glColor3f(0.0f, 1.0f, 0.0f);
				//DrawMapCube(i, j, -99.0f, 300.0f, 100.0f);
				break;
			case '2':
				glPushMatrix();
				glTranslatef((i + 0.5) * SIZE, -100.0f, (j + 0.5)* SIZE);
				clotheseCase->Display();
				//table->Display();
				glPopMatrix();
				break;
			case '3':
				glPushMatrix();
				glTranslatef((i + 0.5) * SIZE, -100.0f, (j + 0.5)* SIZE);
				table->Display();
				castle->Display();
				glPopMatrix();
				break;
			default:
				break;
			}
			
		}
	}

	glPopMatrix();
}

void FirstRoom::DrawSingleFloor(int x, int z)
{
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(x * SIZE, -100.0f, z *SIZE);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f((x + 1) * SIZE, -100.0f, z *SIZE);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f((x + 1) * SIZE, -100.0f, (z + 1) *SIZE);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(x * SIZE, -100.0f, (z + 1) * SIZE);
	glEnd();
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

void FirstRoom::DrawMapCube(int x, int z, float y, float wallHeight, float length) // firstly, drawing normal floor, then drawing unit wall at the center of block, then extend the wall to their neighbours. 
{
	glBegin(GL_QUADS);
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(x * SIZE, y, z *SIZE );
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(x * SIZE, y, (z + 1) *SIZE);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(x * SIZE, wallHeight, (z + 1) *SIZE );
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(x * SIZE, wallHeight, z  *SIZE );
	//front
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(x * SIZE, y, z *SIZE );
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f((x + 1) * SIZE , y, z *SIZE );
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f((x + 1) * SIZE, wallHeight, z *SIZE );
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(x * SIZE , wallHeight, z *SIZE );
	//left
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f((x + 1) * SIZE , y, z *SIZE);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f((x + 1) * SIZE , y, (z + 1) *SIZE );
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f((x + 1) * SIZE , wallHeight, (z + 1) *SIZE );
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f((x + 1) * SIZE , wallHeight, z *SIZE);
	//right
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(x * SIZE , y, (z + 1) *SIZE );
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f((x + 1) * SIZE, y, (z + 1) *SIZE );
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f((x + 1) * SIZE , wallHeight, (z + 1) *SIZE );
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(x * SIZE , wallHeight, (z + 1) *SIZE );
	glEnd();
	
}
