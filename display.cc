#ifndef DISPLAY
#define DISPLAY

#include "sysincludes.h"       

#include "globals.h"

void display(){

    // Bind the texture you want to use and draw the first polygon

    glBindTexture(GL_TEXTURE_2D, textures[0]);
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

    glBindTexture(GL_TEXTURE_2D, textures[1]);
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

// Flush the buffer
    glFlush();

}

#endif