#pragma comment(lib, "SearchLib.lib")
#include <iostream>

namespace SearchLib
{
	std::string getName();
	char checkForOptions();

	bool partialMatchCheck(std::string entry, std::string name);

	void searchResult(std::string name);
	bool searchResultFull(std::string name);
	bool searchResultPartial(std::string name);

	bool searchThreads(std::string name);
}
