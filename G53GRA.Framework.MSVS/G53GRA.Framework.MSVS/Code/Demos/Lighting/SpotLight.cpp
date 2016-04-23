#include "SpotLight.h"


SpotLight::SpotLight(GLenum lightNum, int specialLightFlag) : 
lightNum(lightNum), flag(specialLightFlag), pmFlag(0)
{
// Initialise Ambient Colour (white)
	ambient[0] = 1.0f;
	ambient[1] = 1.0f;
	ambient[2] = 1.0f;
	ambient[3] = 1.0f;
// Initialise Diffuse Colour (white)
	diffuse[0] = 1.0f;
	diffuse[1] = 1.0f;
	diffuse[2] = 1.0f;
	diffuse[3] = 1.0f;
// Initialise Specular Colour (white)
	specular[0] = 1.0f;
	specular[1] = 1.0f;
	specular[2] = 1.0f;
	specular[3] = 1.0f;
// Initialise Attenuation Parameters (a_c = 1, a_l = 0, a_q = 0)
	attenuation[0] = 1.0f;
	attenuation[1] = 0.0f;
	attenuation[2] = 0.0f;
// Initialise Spotlight Direction (0,0,-1)
	spotDir[0] = 0.0f;
	spotDir[1] = 0.0f;
	spotDir[2] = -1.0f;
	spotDir[3] = 1.0f;
// Initialise Spotlight Intensity Decay
	spotExponent = 0.0f;
// Initialise Spotlight Cutoff Angle
	spotCutOff = 45.0f;
}


SpotLight::~SpotLight()
{
}


void SpotLight::SetAmbient(float r, float g, float b, float a)
{
	ambient[0] = r; ambient[1] = g; ambient[2] = b; ambient[3] = a;
}

void SpotLight::SetDiffuse(float r, float g, float b, float a)
{
	diffuse[0] = r; diffuse[1] = g; diffuse[2] = b; diffuse[3] = a;
}

void SpotLight::SetSpecular(float r, float g, float b, float a)
{
	specular[0] = r; specular[1] = g; specular[2] = b; specular[3] = a;
}

void SpotLight::SetAttenuation(float constant, float linear, float quadratic)
{
	attenuation[0] = constant; attenuation[1] = linear; attenuation[2] = quadratic;
}

void SpotLight::SetSpotDirection(float x, float y, float z)
{
	spotDir[0] = x; spotDir[1] = y; spotDir[2] = z; spotDir[3] = 0.0f;
}

void SpotLight::SetSpotExponent(float e)
{
	spotExponent = e;
}

void SpotLight::SetSpotCutOff(float d)
{
	spotCutOff = d;
}

void SpotLight::Display()
{
	// Draw a sphere representing the spotlight with a line showing its direction
	glDisable(GL_LIGHTING); // Disable lighting effects on sphere object (since it is "light source")

	glPushAttrib(GL_ALL_ATTRIB_BITS); // Save style states
	glColor3f(diffuse[0], diffuse[1], diffuse[2]); // Set light to be same colour as diffuse

	glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2]);		// Translate to position
		glScalef(scale[0], scale[1], scale[2]);     // Scale appropriately
		glutSolidSphere(2.0, 40, 40);               // Draw sphere representing light source

		glRotatef(rotation[1], 0.f, 1.f, 0.f);      // Orient to spotlight direction
		glRotatef(rotation[0], 1.f, 0.f, 0.f);
		glRotatef(rotation[2], 0.f, 0.f, 1.f);

		glLineWidth(2.f);
		glBegin(GL_LINES);							// Draw line representing spotlight direction
			glVertex3f(0.f, 0.f, 0.f);
			glVertex3f(10.f*spotDir[0], 10.f*spotDir[1], 10.f*spotDir[2]);
		glEnd();
	glPopMatrix();

	glPopAttrib();
	glEnable(GL_LIGHTING);						// Reenable lighting to affect other objects after this is drawn
}

void SpotLight::Update(const double& deltaTime)
{
// Change properties based on constructor flag
	switch (flag)
	{
		case 1: // A light that spins on its x-axis
			rotation[0] += 100.f*(float)deltaTime;
			break;
		case 2: // A light that spins on its y-axis
			rotation[1] += 200.f*(float)deltaTime;
			break;
		case 3: // A light that spins on its z-axis
			rotation[2] += 150.f*(float)deltaTime;
			break;
		case 4: // A stationary light that has oscillating red diffuse
			if (pmFlag == 1) // increase red
			{
				diffuse[0] += (float)deltaTime;
				if (diffuse[0] > 1.f)
				{
					diffuse[0] = 1.f;
					pmFlag     = 0;
				}
			} 
			else // decrease red
			{
				diffuse[0] -= (float)deltaTime;
				if (diffuse[0] < 0.f)
				{
					diffuse[0] = 0.f;
					pmFlag     = 1;
				}
			}
			break;
		case 5: // A light spinning in all directions with oscillating blue diffuse
			rotation[0] += 10.f*(float)deltaTime;
			rotation[1] += 15.f*(float)deltaTime;
			rotation[2] += 20.f*(float)deltaTime;
			if (pmFlag == 1) // increase blue
			{
				diffuse[2] += 0.5f*(float)deltaTime;
				if (diffuse[2] > 1.f)
				{
					diffuse[2] = 1.f;
					pmFlag     = 0;
				}
			}
			else // decrease blue
			{
				diffuse[2] -= 0.5f*(float)deltaTime;
				if (diffuse[2] < 0.f)
				{
					diffuse[2] = 0.f;
					pmFlag     = 1;
				}
			}

			break;
		default:
			// normal spotlight no motion no colour change
			break;
	}
	// Turn lighting on
	glEnable(GL_LIGHTING);

	// Enable the light we wish to use
	glEnable(lightNum);

	// Set the colours of each of the components of the light source
	glLightfv(lightNum, GL_AMBIENT, ambient);
	glLightfv(lightNum, GL_DIFFUSE, diffuse);
	glLightfv(lightNum, GL_SPECULAR, specular);

	// Set the lights attentuation i.e. how quickly the light fades as we move away
	glLightf(lightNum, GL_CONSTANT_ATTENUATION, attenuation[0]);
	glLightf(lightNum, GL_LINEAR_ATTENUATION, attenuation[1]);
	glLightf(lightNum, GL_QUADRATIC_ATTENUATION, attenuation[2]);

	// Set the lights spotlight parameters
	glLightf(lightNum, GL_SPOT_EXPONENT, spotExponent);
	glLighti(lightNum, GL_SPOT_CUTOFF, spotCutOff);

	glPushMatrix();
		// set the postion of the light source
		GLfloat lightPos[] = { pos[0], pos[1], pos[2], 1.f };
		glLightfv(lightNum, GL_POSITION, lightPos);

		// apply any rotation to the spotlight direction we may wish to apply here
		glRotatef(rotation[1], 0.0, 1.0, 0.0);
		glRotatef(rotation[0], 1.0, 0.0, 0.0);
		glRotatef(rotation[2], 0.0, 0.0, 1.0);

		// set the spotlight direction
		glLightfv(lightNum, GL_SPOT_DIRECTION, spotDir);
	glPopMatrix();

}