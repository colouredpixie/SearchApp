// SearchLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "SearchLib.h"

#include <iostream>
#include <thread>
#include <condition_variable>

#include <filesystem>
namespace fs = std::filesystem;

namespace SearchLib
{

    std::string path = "C:\\";

    std::vector<std::thread> threads;
    std::condition_variable condVar;
    std::mutex condVarMutex;
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

    char checkForOptions() {
        char option;
        do {
            std::cout << "Do you want (f)ull-word, (p)artial or (t)hreaded search (f/p/t): ";
            std::cin >> option;

            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } while (option != 'f' && option != 'p' && option != 't');

        return option;
    }

    bool partialMatchCheck(std::string entry, std::string clue) {
        if (entry.find(clue) != std::string::npos)
            return true;
        return false;
    }

    void searchResult(std::string name) {
        switch (checkForOptions()) {
        case('f'): {
            if (searchResultFull(name)) {
                std::cout << "Full match search entries complete.\n";
            }
            else
                std::cout << "No entries found.\n";
            break;
        }
        case('p'): {
            if (searchResultPartial(name)) {
                std::cout << "Partial match search entries complete.\n";
            }
            else
                std::cout << "No entries found.\n";
            break;
        }
        case('t'): {
            if (searchThreads(name)) {
                std::cout << "Threaded partial match search entries complete.\n";
            }
            else
                std::cout << "No entries found.\n";
            break;
            }
        default:
            std::cout << "Got a faulty option.\n";
        }
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

    auto threadLambda = [](std::string name, std::string lambdaPath) {
        for (const auto& entry : fs::directory_iterator(lambdaPath, fs::directory_options::skip_permission_denied)) {
            if(!terminate) {
            std::string tempName = entry.path().stem().string();

            if (entry.is_regular_file() && partialMatchCheck(tempName, name)) {
                std::cout << entry.path() << std::endl;

                terminate = true;
                condVar.notify_all();
                
                return true;
            }
        }
            return false;
    }
        return false;
    };

    bool searchThreads(std::string name) {
        for (const auto& entry : fs::directory_iterator(path, fs::directory_options::skip_permission_denied)) {
            std::string tempName = entry.path().stem().string();

            if (entry.is_regular_file() && partialMatchCheck(tempName, name)) {
                std::cout << entry.path() << std::endl;

                terminate = true;
                return true;
            }
            if (entry.is_directory() && threads.size() <= 8) {
                threads.push_back(std::thread(threadLambda, name, entry.path().string()));
            }
        }

        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }

        return false;
    }
}
