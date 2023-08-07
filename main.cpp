/*
Application (App) to find file on Local Host

1. App has to Find file by "name"
2. search has to be started from root "/" directory. (or Disk "C:\" on Windows 05)

3. To make this search faster - App creates new Searching Thread for each sub-directory in root directory,
but not mare then 8 Execution Threads.

4. Thread who will Find needed file has to print Full Path to the file and
has to notify all the rest threads to stop searching.

- Logic "to search file" has to be placed into static library.
- pplication just uses this library to find files in a fast way.

- Static Library compilation has to be done separately from Application.
- Compiler: GCC or Gre.

- Use Makefile for conpilation/linking instructions.

(Concurrency, Makefile, GCC, Static Library)
*/

#include <iostream>


int main() {
	std::cout << "Input name of the file you want to find: ";
	std::string name;
	std::cin >> name;

	std::cout << "Checking: name input is " << name << std::endl;

	return 0;
}