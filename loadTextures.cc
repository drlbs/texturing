#ifndef LOAD_TEXTURES
#define LOAD_TEXTURES

#include "sysincludes.h"    
#include "globals.h"    

// We are going to need to save the memory location of the texture objects in a
// global space, so create an array of pointers for this.  For simplicity we
// will statically assign its size based on the number of textures we are using

    GLuint textureID[3];

void loadTextures(){

    unsigned char* image; // <-- Stores image information
    int width, height;    // <-- Used by SOIL


// Here we will generate a texture ID, give it a name then we bind it to
// a structure type.  Once I bind a texture all subsequent operations
// pertain to that texture until I either unbind it or bind another texture. 
    glGenTextures(1, &textureID[0]);  
    glBindTexture(GL_TEXTURE_2D, textureID[0]); 

// Here I am setting up filters and functions to be used for the MIPMAPS.  Rather than
// go into the details of MIPMAPS here, take a look at your text of just read
// the OpenGL docs.  The important thing is that these items get stored in the
// data structure along with the texture.  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// Now we call one of the SOIL library functions to load the image data into a character array.
// glTexImage2D takes the data and coverts it into the internal format used by OpenGL.
    image = SOIL_load_image("./textures/smiley_256_256.jpg", &width, &height, 0, SOIL_LOAD_RGB); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

// glGenerateMipmap is a function that, at this time, is accessed via GLEW.  It builds the various
// MIPMAP representations of the texture and stores them in the object as well. 
    glGenerateMipmap(GL_TEXTURE_2D); 

// Be nice and clean up after yourself.
    SOIL_free_image_data(image);

// Now Repeat the Process for the Second Texture

    glGenTextures(1, &textureID[1]);  
    glBindTexture(GL_TEXTURE_2D, textureID[1]); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    image = SOIL_load_image("./textures/up_256_256.png", &width, &height, 0, SOIL_LOAD_RGB); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glGenerateMipmap(GL_TEXTURE_2D); 

// And now do it for the earth image for the sphere

    glGenTextures(1, &textureID[2]);  
    glBindTexture(GL_TEXTURE_2D, textureID[2]); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    image = SOIL_load_image("./textures/earthmap1k.jpg", &width, &height, 0, SOIL_LOAD_RGB); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glGenerateMipmap(GL_TEXTURE_2D); 

//  Clean up after ourselves

    SOIL_free_image_data(image);

    glBindTexture(GL_TEXTURE_2D, 0);   


}

#endif
