// SearchLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "SearchLib.h"

#include <iostream>
#include <filesystem>
//namespace fs = std::filesystem;

std::string path = "C:\\";


std::string getName() {
    //std::cout << "Search query should be a single word without spaces.\n";
    std::cout << "Input name of the file you want to find: ";
    std::string name;
    std::cin >> name;

    std::cin.clear();
    std::cin.ignore(32767, '\n');

    return name;
}

bool checkForOptions() {
    char option;
    do {
        std::cout << "Do you want full or partial search (f/p): ";
        std::cin >> option;

        std::cin.clear();
        std::cin.ignore(32767, '\n');
    } while (option != 'f' && option != 'p');


    switch (option) {
    case('f'): {
        return true;
        break;
    }
    case('p'): {
        return false;
        break;
    }
    default: 
        return false;
    }
}

bool partialMatchCheck(std::string entry, std::string clue) {
    if (entry.find(clue) != std::string::npos)
        return true;
    return false;
}

void searchResult(std::string name) {
    if (checkForOptions()) {
        if (searchResultFull(name))
            std::cout << "Full match search entries complete.\n";
        else 
            std::cout << "No entries found.\n";
    }
    else {
        if (searchResultPartial(name)) 
            std::cout << "Partial match search entries complete.\n";
        else
            std::cout << "No entries found.\n";
    }
}

bool searchResultFull(std::string name) {
    int counter = 0;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        std::string tempName = entry.path().stem().string();
        if (entry.is_regular_file() && tempName == name) {
            std::cout << entry.path() << std::endl;
            counter++;
        }
    }
    return counter;
}

bool searchResultPartial(std::string name) {
    int counter = 0;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        std::string tempName = entry.path().stem().string();

        if (entry.is_regular_file() && partialMatchCheck(tempName, name)) {
        std::cout << entry.path() << std::endl;
        counter++;
        }
    }
    return counter;
}