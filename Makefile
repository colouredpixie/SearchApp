#
# A simple makefile for compiling SearchApp
#

SRC=./
TARGET=./x64/Debug
CXX = g++
#LIBS = -L. -lSearchLib -static

all: default clean

#default: SearchLib.lib SearchApp.out
#    $(CXX) -o $(TARGET)/SearchApp.exe SearchApp.out $(LIBS)  

#SearchLib.lib:
#    ar rcs $(TARGET)/SearchLib.lib SearchLib.cpp 

default: main.o
	$(CXX) -o $(TARGET)/SearchApp.exe main.o

main.o:
	$(CXX) -c main.cpp -o main.o 

clean:
	rm -rf $(SRC)/main.o 