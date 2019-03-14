include ../Makefile.inc

# Build Code targets 

all: tex1 

OPT = -O2
HEADERS = sysincludes.h globals.h ../lib/SOIL/SOIL.h  
OPTHDRSLOC = -I../lib/SOIL
OPTLIBSLOC = -L../lib/SOIL
LDLIBS = -lGL -lGLU -lGLEW -lglut -lSOIL

OBJS   = myInit.o loadTextures.o reshape.o display.o

all : ../tex1

tex1 : main.o $(OBJS) $(HEADERS)  
	$(CPP) $(OPT) main.o -o ../tex1 $(OBJS) $(OPTHDRSLOC) $(OPTLIBSLOC)  $(LDLIBS)

main.o : main.cc $(HEADERS) 
	$(CPP) $(OPT) main.cc -c  

myInit.o : myInit.cc $(HEADERS) 
	$(CPP) $(OPT) myInit.cc -c 

loadTextures.o : loadTextures.cc $(HEADERS) 
	$(CPP) $(OPT) loadTextures.cc -c 

reshape.o : reshape.cc $(HEADERS) 
	$(CPP) $(OPT) reshape.cc -c 

display.o : display.cc $(HEADERS) 
	$(CPP) $(OPT) display.cc -c

clean:
	rm *.o
	touch *.cc

pristine:
	rm *.o
	touch *.cc
	rm ../tex1
