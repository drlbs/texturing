#ifndef INIT
#define INIT

#include "sysincludes.h"

GLuint metalTexture;

void loadTexture() 
{

unsigned char* image;
int width, height;

   /* Now load the texture */ 

   //metalTexture = SOIL_load_OGL_texture("./textures/stock-photo-metal-texture-114803308.jpg",
//   metalTexture = SOIL_load_OGL_texture("./textures/smiley_1024_1024.jpg",
   //metalTexture = SOIL_load_OGL_texture("./textures/goldmetal.jpeg",
/*                                           SOIL_LOAD_AUTO,
                                           SOIL_CREATE_NEW_ID,
                                           SOIL_FLAG_POWER_OF_TWO | 
                                         SOIL_FLAG_TEXTURE_REPEATS    );
*/

   image = SOIL_load_image("./textures/smiley_1024_1024.jpg", &width, &height, 0, SOIL_LOAD_RGB); 
   glGenTextures(1, &metalTexture);  
   glBindTexture(GL_TEXTURE_2D, metalTexture); 
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
   //glGenerateMipmap(GL_TEXTURE_2D);

}

#endif /* INIT */

