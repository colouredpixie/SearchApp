#
# A makefile for building SearchApp
#

TARGET=./x64/Debug
LIBPATH = F:/programs/source/repos/GLTest24/SearchLib
CC = g++
LIBS = -L./x64/Debug -lSearchLib -static 

all: default clean

default: main.o 
	$(CC) -o $(TARGET)/SearchApp.exe main.o $(LIBS)  

main.o:
	$(CC) -c main.cpp -o main.o 

clean:
	rm main.o 