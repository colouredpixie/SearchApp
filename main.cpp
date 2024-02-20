#include <iostream>
#include "SearchLib.h"


int main() {

	std::string name = SearchLib::getName();
	SearchLib::searchResult(name);

	system("pause");

	return 0;
}