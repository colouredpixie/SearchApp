#
# A makefile for building SearchApp
#

TARGET=./x64/Debug
CC = g++
LIBS = -L./x64/Debug/ -lSearchLib -static

all: default clean

default: main.o 
	$(CC) -o $(TARGET)/SearchApp.exe main.o $(LIBS)  

main.o:
	$(CC) -c -std=c++17 main.cpp -o main.o 

clean:
	rm main.o 