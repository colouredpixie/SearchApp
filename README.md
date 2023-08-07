# SearchApp

Application (App) to find file on Local Host

App searches file by "name" or "part of the name" user input, starting from Disk "C:\".
Result is first match in root directory or sub-directory, which is printed as a full path.

Logic is implemented in a separately compiled library (GCC), while main App only calls the function from it.

TODO:  App to creates new thread for each sub-directory in root directory, but not mare then 8 execution threads. 
Thread that finds needed file first has to print full path to the file and notify all the rest threads to stop searching (std::condition_variable::notify_all).

TODO: Test Makefile for CLI compilation and linking.

(Concurrency, Makefile, GCC, Static Library)