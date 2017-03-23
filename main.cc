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

    GLuint metalTexture;
    unsigned char* image;
    int width, height;

    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    gluLookAt(  20.0,   20.0,  20.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);

   image = SOIL_load_image("./textures/smiley_1024_1024.jpg", &width, &height, 0, SOIL_LOAD_RGB); 
   glGenTextures(1, &metalTexture);  
   glBindTexture(GL_TEXTURE_2D, metalTexture); 
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
   //glGenerateMipmap(GL_TEXTURE_2D); 

    glBegin(GL_POLYGON);

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
