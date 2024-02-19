# SearchApp

Application (App) to find file on Local Host

App searches file by "name" or "part of the name" user input, starting from Disk "C:\\".
Options include a multithreaded search (up to 8 execution threads), which looks through subfolders in separate threads and terminates on first find.
Result is first match in root directory or sub-directory, which is printed as a full path.

Logic is implemented in a separately compiled library (GCC), while main App only calls the function from it.

TODO: Test Makefile for CLI compilation and linking.

(Concurrency, Makefile, GCC, Static Library)