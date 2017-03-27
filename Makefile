
CC = g++
OPT = -O2
OBJS = myInit.o loadTextures.o reshape.o display.o 
HEADERS = SOIL.h sysincludes.h globals.h 
LDLIBS = -lGL -lGLU -lGLEW -lglut libSOIL.a

all : tex1

tex1 : main.o $(OBJS) $(HEADERS)
	$(CC) $(OPT) main.o -o tex1 $(OBJS) $(LDLIBS)

main.o : main.cc globals.h
	$(CC) $(OPT) main.cc -c

myInit.o : myInit.cc globals.h
	$(CC) $(OPT) myInit.cc -c 

loadTextures.o : loadTextures.cc globals.h 
	$(CC) $(OPT) loadTextures.cc -c

reshape.o : reshape.cc 
	$(CC) $(OPT) reshape.cc -c

display.o : display.cc globals.h 
	$(CC) $(OPT) display.cc -c

clean:
	rm *.o
