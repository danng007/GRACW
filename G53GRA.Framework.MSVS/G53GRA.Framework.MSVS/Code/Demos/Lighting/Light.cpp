#include "Light.h"
#include <cmath>

Light::Light() : t(0.0), radius(200.0)
{
	ambient[0] = 0.15;  // Set ambient colour of the light
	ambient[1] = 0.15;
	ambient[2] = 0.1;
	ambient[3] = 1.0;

	diffuse[0] = 0.8;   // Set diffuse colour of the light
	diffuse[1] = 0.0;
	diffuse[2] = 0.0;
	diffuse[3] = 1.0;

	specular[0] = 1.0;  // Set specular colour of the light
	specular[1] = 1.0;
	specular[2] = 1.0;
	specular[3] = 1.0;

	positionalLight = 1.0; // Set this to 1.0 for positional light or 0.0 for directional light
}


Light::~Light()
{
}


void Light::Display()
{
	// Some basic code to draw the position and direction of the light.
	// Not suitable for a directional light source, as directional light has no position.

	if (positionalLight == 1.0)
	{
		// Disable lighting on this geometry it will only be coloured by a glColor3 call
		glDisable(GL_LIGHTING);

		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);

			glColor4fv(diffuse);
			glTranslatef(pos[0], pos[1], pos[2]);
			glutSolidSphere(10, 10, 10);
			glBegin(GL_LINES);
				glVertex3f(0.f, 0.f, 0.f);
				glVertex3f(-pos[0], -pos[1], -pos[2]);
			glEnd();

		glPopAttrib();
		glPopMatrix();
	}
	glEnable(GL_LIGHTING);	 // turn lighting on

}

void Light::Update(const double& deltaTime)
{
	t += deltaTime;
	pos[0] = radius*cos(t);
	pos[1] = radius*sin(t);

	glEnable(GL_LIGHTING);

	/*	Lighting property settings:
	*		 glLightfv( GLenum light , GLenum pname , const GLfloat* params )
	*           |      ____________   ____________   _____________________
	* accepts float vector  |              |                   |
	*                specifies light       |           parameter values
	*             GL_LIGHTi for i=0..8     |      (as defined in constructor)
	*								 light parameter
	*					either GL_AMBIENT, GL_DIFFUSE, GL_SPECULAR,
	*					     GL_POSITION or GL_SPOT_DIRECTION
	*
	* Some properties take only single value parameters, so you must use glLightf() instead
	* The following properties take single values only:
	*    GL_SPOT_EXPONENT (0..128), GL_SPOT_CUTOFF (0..90, 180), GL_CONSTANT_ATTENUATION,
	*        GL_LINEAR_ATTENUATION, and GL_QUADRATIC ATTENUATION
	*/

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Set all lights attentuation, i.e. how quickly the light fades from position
	//glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.025);

	float lPosition[4] = { pos[0], pos[1], pos[2], positionalLight };
	glLightfv(GL_LIGHT0, GL_POSITION, lPosition);

	glEnable(GL_LIGHT0); // enable GL_LIGHT0 with these defined properties
}