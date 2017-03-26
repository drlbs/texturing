#ifndef MYINIT
#define MYINIT

#include "sysincludes.h"        

#include "globals.h"

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

// Enable Texturing and the Depth Buffer
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

#ifdef DEBUG
    printf( "OpenGL Version: %s\n", glGetString(GL_VERSION)); 
#endif

    loadTextures();

}


#endif 
