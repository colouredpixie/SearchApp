#
# A simple makefile for compiling SearchApp
#

SRC=./
TARGET=./x64/Debug
CXX = gcc
LIBS = -L. -lSearchLib -static

all: clean default

default: SearchLib.lib SearchApp.out
    $(CXX) -o $(TARGET)/SearchApp.exe SearchApp.out $(LIBS)  

SearchLib.lib:
    ar rcs $(TARGET)/SearchLib.lib SearchLib.cpp 

SearchApp.out: 
    $(CXX) -c main.cpp -o SearchApp.out 

clean: 
	rm -rf $(SRC)/$(wildcard *.out)