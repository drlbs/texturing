//
//
//  Colloidal Dynamics Monte Carlo Stepper
//
//  Andrew J. Pounds, Ph.D.
//  Department of Chemistry 
//  Mercer University
//  Spring 2013
//
//  Based on Meyer, et. al.  J. Phys. Chem B 110 (2006) 6040.
//

#include "sysincludes.h" 
extern GLuint metalTexture;

void loadTexture();

int windowsize;

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
}


void display(){


    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    gluLookAt(  20.0,   20.0, -20.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    loadTexture();
    glBegin(GL_LINES);

    glTexCoord2d( 0.0, 0.0);   glVertex2d( 0.0, 0.0 );
    glTexCoord2d( 0.0, 1.0);   glVertex2d( 0.0, 10.0 );
    glTexCoord2d( 1.0, 1.0);   glVertex2d( 10.0, 10.0 );
    glTexCoord2d( 1.0, 0.0);   glVertex2d( 10.0, 0.0 );

    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);

}


int main(int argc, char** argv) {
    windowsize=800;    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH  );
    glutInitWindowSize (windowsize, windowsize); 
    glutCreateWindow("Texture Example");
    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
} 
