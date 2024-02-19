#include <iostream>
//#include "lib/SearchLib.h"
#include "F:\programs\source\repos\GLTest24\SearchLib\SearchLib.h"

int main() {

	std::string name = SearchLib::getName();
	SearchLib::searchResult(name);

	system("pause");

	return 0;
}