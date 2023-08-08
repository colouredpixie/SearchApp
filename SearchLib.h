#pragma once
#include <iostream>


namespace SearchLib
{
	std::string getName();
	bool checkForOptions();

	bool partialMatchCheck(std::string entry, std::string name);

	void searchResult(std::string name);
	bool searchResultFull(std::string name);
	bool searchResultPartial(std::string name);
}