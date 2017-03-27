#ifndef MAIN 
#define MAIN 

#include "sysincludes.h"        
#include "globals.h"

void myInit();
void display();
void reshape(int,int);

int main(int argc, char** argv) {
    int windowsize;
    windowsize=800;    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH  );
    glutInitWindowSize (windowsize, windowsize); 
    glutCreateWindow("Texture Example");
    glewInit();
    myInit();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    
}

#endif 
