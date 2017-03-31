CC=g++
CFLAGS=-Wall -Wextra
ISTRING=-I./
LFLAGS=-lGLU -lGL -lglut
EXENAME=openglprog

build:
	$(CC) $(CFLAGS) $(ISTRING) main.cpp $(LFLAGS) -o $(EXENAME) 

check:
	$(CC) $(CFLAGS) -c $(ISTRING) main.cpp
	$(CC) $(CFLAGS) -c $(ISTRING) ColoredCube.cpp
	$(CC) $(CFLAGS) -c $(ISTRING) ColoredCube.hpp
	$(CC) $(CFLAGS) -c $(ISTRING) WindowObject.cpp
	$(CC) $(CFLAGS) -c $(ISTRING) WindowObject.hpp
