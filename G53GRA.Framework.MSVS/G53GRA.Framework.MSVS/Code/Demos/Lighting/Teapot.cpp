#include "Teapot.h"


Teapot::Teapot()
{
}


Teapot::~Teapot()
{
}

void Teapot::Display()
{

	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);
		
		glDisable(GL_COLOR_MATERIAL); // stops glColor affecting properties of surface

		GLfloat mat_ambient[] =   { 0.f, 0.f, 0.9f, 1.f   }; // Define the ambient material colour property K_a
		GLfloat mat_diffuse[] =   { 0.9f, 0.0f, 0.0f, 1.f }; // Define the diffuse material colour property K_d
		GLfloat mat_specular[] =  { 1.f, 1.f, 1.f, 1.f    }; // Define the specular material colour property K_s
		GLfloat mat_shininess[] = { 100.0 };                 // Define the shininess/specular exponent factor n ( capped between 0.0 and 128.0 )

		/* Material property settings:
		 *     glMaterialfv( GLenum face , GLenum pname , const GLfloat* params )
		 *		     |       ___________   ____________   _____________________
		 *  accepts float vector  |              |                  |
		 *				   specifies face        |           parameter values
		 *           either GL_FRONT or GL_BACK  |          (as defined above)
		 *             or GL_FRONT_AND_BACK      |
		 *                               material parameter
		 *                   either GL_AMBIENT, GL_DIFFUSE, GL_SPECULAR
		 *                GL_EMISSION, GL_SHININESS or GL_AMBIENT_AND_DIFFUSE
		 */

		// Material properties for OpenGL implementation of Phong reflectance model
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glPushMatrix();
				glFrontFace(GL_CW); // Swap winding order for back face culling (so clockwise ordering is now considered front face)
									//    because glutSolidTeapot has the wrong polygon winding

				glRotatef(rotation[1], 0.f, 1.f, 0.f);	// Rotate around y-axis

				glutSolidTeapot(1.0);                   // Draw solid teapot (with default normals)

				glFrontFace(GL_CCW); // Revert to previous winding order (front face is now counterclockwise delared vertices)
		glPopMatrix();

		glEnable(GL_COLOR_MATERIAL); // Re-enable the effects of calls to glColor

	glPopAttrib();
	glPopMatrix();

}

void Teapot::Update(const double& deltaTime)
{
	rotation[1] += 10.f*(float)deltaTime;  // Update rotation around y-axis over time

	if (rotation[1] > 360.f)               // If greater than full circle, start from 0 again (to prevent eventual overflow)
		rotation[1] -= 360.f;
}