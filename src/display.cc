#ifndef DISPLAY_FUNC
#define DISPLAY_FUNC

#include "sysincludes.h"       

#include "globals.h"

void display(){

    // Enable Texturing and the Depth Buffer
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


    // Bind the texture you want to use and draw the first polygon

    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glPushMatrix();
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,-10.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 10.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 10.0, 10.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 10.0,  0.0 );

    glEnd();

    // Bind the second you want to use and draw the first polygon

    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glPushMatrix();
    glRotatef(90.0,1.0,0.0,0.0);
    glTranslatef(0.0,-10.0,-10.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 10.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 10.0, 10.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 10.0,  0.0 );

    glEnd();

    glPopMatrix();

    // Bind the texture and draw the sphere

    glBindTexture ( GL_TEXTURE_2D, textureID[2]);
    glTranslatef(-5.0,5.0,-5.0);
    glScalef(5.0,5.0,5.0);
    glPushMatrix();
    glRotatef(90.0,0.0,1.0,0.0);
    glRotatef(-45.0,0.0,0.0,1.0);
// The next line fixes the mirrored texture map
//    glScalef(1.0,-1.0,1.0);
    gluSphere( earth, 0.9, 36, 72);
    glPopMatrix();
 
    // Flush the buffer
    glFlush();

    // For completeness turn off these options
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);

}

#endif
