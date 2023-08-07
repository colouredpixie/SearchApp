// SearchLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "SearchLib.h"

#include <iostream>
#include <thread>
#include <filesystem>
namespace fs = std::filesystem;

namespace SearchLib
{

    std::string path = "C:\\";
    std::vector<std::thread> threads;
    int threadCount = 0;
    bool terminate = false;


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
        }
        else if (searchResultPartial(name)) {
            std::cout << "Partial match search entries complete.\n";
        }
        else 
            std::cout << "No entries found.\n";
        
    }

    bool searchResultFull(std::string name) {
        for (const auto& entry : fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied)) {
            std::string tempName = entry.path().stem().string();
            if (entry.is_regular_file() && tempName == name) {
                std::cout << entry.path() << std::endl;
                return true;
            }
        }
        return false;
    }

    bool searchResultPartial(std::string name) {
        for (const auto& entry : fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied)) {
            std::string tempName = entry.path().stem().string();

            if (entry.is_regular_file() && partialMatchCheck(tempName, name)) {
                std::cout << entry.path() << std::endl;
                return true;
            }
        }
        return false;
    }
}


/*
    auto lambda = [](std::string name, std::string path) {

        for (const auto& entry : fs::directory_iterator(path, fs::directory_options::skip_permission_denied)) {
            std::string tempName = entry.path().stem().string();
            if (entry.is_regular_file() && partialMatchCheck(tempName, name)) {
                std::cout << "First entry is: " << entry.path() << std::endl;

                terminate = true;
                //std::condition_variable::notify_all();
                return true;
            }
        }
        return false;
    };

    void searchThreads(std::string name, std::string path) {
        while (!terminate) {
            threads.push_back(std::thread(lambda, name, path));
            for (const auto& entry : fs::directory_iterator(path)) {

                if (entry.is_directory()) {
                    std::string tempFolder = entry.path().string();
                    threadCount++;
                    std::cout << threadCount << std::endl;
                    threads.push_back(std::thread(lambda, name, tempFolder));


                    std::cout << threadCount << std::endl;

                }
            }
            if (threadCount >= 8) {
                threads[8].sleep_for(100);
            }
            for (int i = 0; i < 8; i++) {
                threads[i].join();
            }

            return false;
        }
    }
}
*/