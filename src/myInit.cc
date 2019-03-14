#ifndef MYINIT
#define MYINIT

#include "sysincludes.h"        
#include "globals.h"

GLUquadric *earth;

void loadTextures();



void myInit(){

// This sets up most of the OpenGL options

    glClearColor(0.0,0.0,0.0,0.0);

// Set up a 3D Viewing perspective pulled back from the X-Y plane looking down
// at the first quadrant.

    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    gluLookAt(  20.0,   20.0,   20.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up


#ifdef DEBUG
    printf( "OpenGL Version: %s\n", glGetString(GL_VERSION)); 
#endif

    loadTextures();

    earth = gluNewQuadric();
    gluQuadricTexture( earth, GL_TRUE);
}


#endif 
