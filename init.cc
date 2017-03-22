#ifndef INIT
#define INIT

#include "sysincludes.h"

GLuint metalTexture;

void init() 
{

   /* Now load the texture */ 

   metalTexture = SOIL_load_OGL_texture("./textures/stock-photo-metal-texture-114803308.jpg",
   //metalTexture = SOIL_load_OGL_texture("./textures/goldmetal.jpeg",
                                           SOIL_LOAD_AUTO,
                                           SOIL_CREATE_NEW_ID,
                                           SOIL_FLAG_POWER_OF_TWO | 
                                           SOIL_FLAG_TEXTURE_REPEATS    );

}

#endif /* INIT */

