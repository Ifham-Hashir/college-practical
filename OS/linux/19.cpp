#include <iostream>
#include <cstdlib> // For system()

using namespace std;

int main() {
    // 1. Execute 'find' command to search for a file or directory (example: searching for files with .cpp extension)
    cout << "\nExecuting 'find' command to search for .cpp files in the current directory:\n";
    system("find . -name '*.cpp'");

    // 2. Execute 'locate' command to locate a specific file (example: looking for 'test_file.txt')
    cout << "\nExecuting 'locate' command to find a file named 'test_file.txt':\n";
    system("locate test_file.txt");

    // 3. Execute 'date' command to display the current date and time
    cout << "\nExecuting 'date' command to display the current date and time:\n";
    system("date");

    // 4. Execute 'cal' command to display the current month's calendar
    cout << "\nExecuting 'cal' command to display the calendar for the current month:\n";
    system("cal");

    // 5. Execute 'time' command to measure execution time of a simple command (example: 'ls')
    cout << "\nExecuting 'time' command to measure the execution time of the 'ls' command:\n";
    system("time ls");

    return 0;
}

// Executing 'find' command to search for .cpp files in the current directory:
// ./main.cpp
// ./examples/sample.cpp

// Executing 'locate' command to find a file named 'test_file.txt':
// /home/user/documents/test_file.txt
// /usr/share/examples/test_file.txt

// Executing 'date' command to display the current date and time:
// Wed Dec 12 14:45:12 IST 2024

// Executing 'cal' command to display the calendar for the current month:
//      December 2024      
// Su Mo Tu We Th Fr Sa  
//  1  2  3  4  5  6  7  
//  8  9 10 11 12 13 14  
// 15 16 17 18 19 20 21  
// 22 23 24 25 26 27 28  
// 29 30 31               

// Executing 'time' command to measure the execution time of the 'ls' command:
// file1.txt  file2.txt  program.cpp

// real    0m0.001s
// user    0m0.000s
// sys     0m0.001s
