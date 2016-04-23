#include "MultiLight.h"
#include <cmath>

MultiLight::MultiLight() : t(0.0), radius(200.0), show0(true), show1(true), show2(true), show3(true)
{
// Direction Light (the 4th component is 0): like the sun, rays are parallel and every thing is light as though the light hit it at a given direction.

// Positional Light (the 4th component is 1): like a lamp in a room, objects are light based on the position and distance from the light source.


/*==============================================================================================================
 * LIGHT0 PARAMETERS (yellow directional light)
 *==============================================================================================================*/

	ambient0[0] = 0.15f;  // Set the ambient colour of light 0 to dull yellow
	ambient0[1] = 0.15f;
	ambient0[2] = 0.f;
	ambient0[3] = 1.f;

	diffuse0[0] = 0.5f;   // Set the diffuse colour of light 0 to pale yellow
	diffuse0[1] = 0.5f;
	diffuse0[2] = 0.f;
	diffuse0[3] = 1.f;

	specular0[0] = 0.f;  // Set no specular colour on light 0
	specular0[1] = 0.f;
	specular0[2] = 0.f;
	specular0[3] = 0.f;

	position0[0] = 1.f;   // Set the direction of light 0
	position0[1] = 1.f;
	position0[2] = 1.f;
	position0[3] = 0.f;   // Mark light 0 as a directional light source

/*==============================================================================================================
* LIGHT1 PARAMETERS (red positional light)
*==============================================================================================================*/
	
	ambient1[0] = 0.15f;  // Set the ambient colour of light 1 to pale red
	ambient1[1] = 0.f;
	ambient1[2] = 0.f;
	ambient1[3] = 1.f;

	diffuse1[0] = 1.f;   // Set the diffuse colour of light 1 to red
	diffuse1[1] = 0.f;
	diffuse1[2] = 0.f;
	diffuse1[3] = 1.f;

	specular1[0] = 1.f;  // Set the specular colour of light 1 to red
	specular1[1] = 0.f;
	specular1[2] = 0.f;
	specular1[3] = 1.f;

	position1[0] = (float)radius; // Set the position of light 1
	position1[1] = 0.f;
	position1[2] = 0.f;
	position1[3] = 1.f;    // Mark light 1 as a positional light source

/*==============================================================================================================
 * LIGHT2 PARAMETERS (green positional light)
 *==============================================================================================================*/
	ambient2[0] = 0.f;  // Set the ambient colour of light 2 to pale green
	ambient2[1] = 0.15f;
	ambient2[2] = 0.f;
	ambient2[3] = 1.f;

	diffuse2[0] = 0.f;   // Set the diffuse colour of light 2 to green
	diffuse2[1] = 0.8f;
	diffuse2[2] = 0.f;
	diffuse2[3] = 1.f;

	specular2[0] = 0.f;  // Set the specular colour of light 2 to green
	specular2[1] = 1.f;
	specular2[2] = 0.f;
	specular2[3] = 1.f;

	position2[0] = -(float)radius;  // Set the position of light 2
	position2[1] = 0.f;
	position2[2] = 0.f;
	position2[3] = 1.f;      // Mark light 2 as a positional light source

/*==============================================================================================================
 * LIGHT3 PARAMETERS (blue positional light)
 *==============================================================================================================*/
	ambient3[0] = 0.f;  // Set the ambient colour of light 3 to light blue
	ambient3[1] = 0.f;
	ambient3[2] = 0.25f;
	ambient3[3] = 1.f;

	diffuse3[0] = 0.f;  // Set the diffuse color of light 3 to blue
	diffuse3[1] = 0.f;
	diffuse3[2] = 0.9f;
	diffuse3[3] = 1.f;

	specular3[0] = 0.f;  // Set the specular color of light 3 to blue
	specular3[1] = 0.f;
	specular3[2] = 1.f;
	specular3[3] = 1.f;


	position3[0] = (float)radius;  // Set the position of light 3
	position3[1] = 0.f;
	position3[2] = 0.f;
	position3[3] = 1.f;     // Mark light 3 as a positional light source

}


MultiLight::~MultiLight()
{
}

void MultiLight::Display()
{
	// Some basic code to draw the position and direction of the light,
	// Note: we cannot draw the directional light source, as it has no position, just direction.

	// Disable lighting on this geometry it will only be coloured by a glColor3 call
	glDisable(GL_LIGHTING);
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	// draw the red light that is positioned in world space
	if (show1)
	{
		glPushMatrix();
			glColor3f(diffuse1[0], diffuse1[1], diffuse1[2]);
			glTranslatef(position1[0], position1[1], position1[2]);
			glutSolidSphere(10, 10, 10);
		glPopMatrix();
	}

	// draw the green light that is positioned in world space
	if (show2)
	{
		glPushMatrix();
			glColor3f(diffuse2[0], diffuse2[1], diffuse2[2]);
			glTranslatef(position2[0], position2[1], position2[2]);
			glutSolidSphere(10, 10, 10);
		glPopMatrix();
	}

	// draw the blue light that is positioned in world space
	if (show3)
	{
		glPushMatrix();
			glColor3f(diffuse3[0], diffuse3[1], diffuse3[2]);
			glTranslatef(position3[0], position3[1], position3[2]);
			glutSolidSphere(10, 10, 10);
		glPopMatrix();
	}
	glPopAttrib();

	glEnable(GL_LIGHTING);

}

void MultiLight::Update(const double& deltaTime)
{
	t += deltaTime;

	position1[0] = (float)radius*cos(t - 1.5);
	position1[1] = (float)radius*sin(t - 1.5);
	position2[0] = -(float)radius*cos(t);
	position2[1] = -(float)radius*sin(t);
	position3[0] = (float)radius*cos(t);
	position3[1] = (float)radius*sin(t);

	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular2);
	glLightfv(GL_LIGHT3, GL_AMBIENT, ambient3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specular3);

	// Set the lights attentuation i.e. how quickly the light fades as it moves away
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0025f);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0025f);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0005f);

	// set the positions of lights.
	glLightfv(GL_LIGHT0, GL_POSITION, position0);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	glLightfv(GL_LIGHT2, GL_POSITION, position2);
	glLightfv(GL_LIGHT3, GL_POSITION, position3);

	// enable each of the lights we wish to use
	if (show0) glEnable(GL_LIGHT0); else glDisable(GL_LIGHT0);
	if (show1) glEnable(GL_LIGHT1); else glDisable(GL_LIGHT1);
	if (show2) glEnable(GL_LIGHT2); else glDisable(GL_LIGHT2);
	if (show3) glEnable(GL_LIGHT3); else glDisable(GL_LIGHT3);
}


void MultiLight::HandleKey(unsigned char key, int state, int x, int y){
	if (state != 1) return; // if key not pressed (i.e. ignore key release)

	switch (key)
	{
		case '0':
			show0 = show1 = show2 = show3 = false;
			break;
		case '1':
			show0 = !show0;
			break;
		case '2':
			show1 = !show1;
			break;
		case '3':
			show2 = !show2;
			break; 
		case '4':
			show3 = !show3;
			break;
	}
}