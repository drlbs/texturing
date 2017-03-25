//
//
//  Texturing Example Using SOIL 
//
//  Andrew J. Pounds, Ph.D.
//  Department of Computer Science 
//  Mercer University
//  Spring 2017
//
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
    gluLookAt(  20.0,   20.0,   20.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    printf( "OpenGL Version: %s\n", glGetString(GL_VERSION)); 

    puts("Before glGenTextures");
   glGenTextures(1, &metalTexture);  
   
    puts("Before glBindTextures");
   glBindTexture(GL_TEXTURE_2D, metalTexture); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    puts("Before load_image");
    image = SOIL_load_image("./textures/smiley_1024_1024.jpg", &width, &height, 0, SOIL_LOAD_RGB); 

    puts("Before glTexImage2D");
    printf("%d %d\n", width, height);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    puts("Before glGenerateMipmap");
    glGenerateMipmap(GL_TEXTURE_2D); 

    puts("Before SOIL_free");
     
   SOIL_free_image_data(image);
   //glBindTexture(GL_TEXTURE_2D, 0);

    puts("Before glBegin");

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
    glewInit();
    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
} 
