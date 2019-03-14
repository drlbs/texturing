include ../../Makefile.inc

# Build SOIL targets and make object files for library

all: lib

SOIL.o : SOIL.c
	$(CC) $(CFLAGS) -c SOIL.c

image_DXT.o : image_DXT.c
	$(CC) $(CFLAGS) -c image_DXT.c

image_helper.o : image_helper.c
	$(CC) $(CFLAGS) -c image_helper.c

stb_image_aug.o : stb_image_aug.c
	$(CC) $(CFLAGS) -c stb_image_aug.c

lib: SOIL.o image_DXT.o image_helper.o stb_image_aug.o
	ar -rc libSOIL.a SOIL.o image_DXT.o image_helper.o stb_image_aug.o
	ranlib libSOIL.a

# Commands to clean up the directory

clean:
	rm *.o
	touch *.c

pristine:
	rm *.o
	rm *.a
	touch *.c


