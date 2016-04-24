#include "Tree.h"
#define SIZE 300.0f
Tree::Tree()
{
	setReplaceString('f', "ff-[-& f + ff + < + f] + [+>f--f&-f]");
	angle = 22.5f;
}

Tree::~Tree()
{

}

void Tree::Display()
{
	glPushMatrix();
	glScalef(10.0f, 10.0f, 10.0f);
	char curr;
	for (unsigned int i = 0; i < sequence.size(); i++){
		curr = sequence[i];             // for each char in sequence
		switch (curr){                  // check current char command
		case 'f':                   // draw branch, move forward
			Branch();
			break;
		case '+':                   // yaw clockwise
			glRotatef(-angle, 0.f, 0.f, 1.f);
			break;
		case '-':                   // yaw counter-clockwise
			glRotatef(angle, 0.f, 0.f, 1.f);
			break;
		case '^':                   // pitch clockwise
			glRotatef(-angle, 1.f, 0.f, 0.f);
			break;
		case '&':                   // pitch counter-clockwise
			glRotatef(angle, 1.f, 0.f, 0.f);
			break;
		case '<':                   // roll clockwise
			glRotatef(-angle, 0.f, 1.f, 0.f);
			break;
		case '>':                   //roll counter-clockwise
			glRotatef(angle, 0.f, 1.f, 0.f);
			break;
		case '|':                   // roll upside-down
			glRotatef(180.f, 0.f, 1.f, 0.f);
			break;
		case '[':   // "Save"
			glPushMatrix();
			break;
		case ']':   // "Restore"
			glPopMatrix();
			break;
		default:
			break;
		}
	}
	glPopMatrix();
}

void Tree::Branch()
{
	float res = 0.1f * 3.1415926;                  // resolution (in radians: equivalent to 18 degrees)
	float r = 0.15f;                        // ratio of radius to height
	float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
	float t = 0.f;                          // initialise angle as 0

	do{                                     // create branch with multiple QUADS
		glBegin(GL_QUADS);
		// Create first points
		glVertex3f(x, 0.f, z);          // bottom
		glVertex3f(x, 1.f, z);          // top
		// Iterate around circle
		t += res;                       // add increment to angle
		x = r*cos(t);                   // move x and z around circle
		z = r*sin(t);
		// Close quad
		glVertex3f(x, 1.f, z);          // top
		glVertex3f(x, 0.f, z);          // bottom
		glEnd();
	} while (t <= 2 * 3.1415926);                // full rotation around circle

	glTranslatef(0.f, 1.f, 0.f);            // translate to top of branch
}

void Tree::GetSequence(){
	int gen = 0, j = 0;
	string next;
	bool changed;
	sequence = init;
	char curr;
	while (gen < iter){                     // Iterative scheme
		next = "";                          // Start with blank
		for (unsigned int i = 0; i < sequence.size(); i++){
			curr = sequence[i];             // For each letter in the sequence
			changed = false;
			j = 0;
			for (vector<char>::iterator it = flags.begin(); it != flags.end(); ++it, j++){
				if (curr == *it){           // Iterate through vector of 'flags'
					next += change[j];      // Replace flag with corresponding change string
					changed = true;
					break;
				}
			}
			if (!changed)                   // If current char does not match a flag
				next += curr;               // ... add it to sequence string
		}
		sequence = next;                    // Update sequence string
		gen++;                              // Recurse
	}
}

void Tree::addReplaceString(char flag, string str){
	flags.push_back(flag);                          // Add char to flags
	change.push_back(str);                          // Add string to change
	GetSequence();                                  // Recompute sequence
}

void Tree::setReplaceString(char flag, string str){
	flags.erase(flags.begin(), flags.end());        // Empty flags
	change.erase(change.begin(), change.end());     // Empty change
	flags.push_back(flag);                          // Add char to flags
	change.push_back(str);                          // Add string to change
	GetSequence();                                  // Recompute sequence
}