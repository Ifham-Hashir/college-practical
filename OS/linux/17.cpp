#include <iostream>
#include <cstdlib> // For system()

using namespace std;

int main() {
    string dirName = "test_directory";

    // 1. Print the current working directory (pwd)
    cout << "\nExecuting 'pwd' command:\n";
    system("pwd");

    // 2. Create a directory (mkdir)
    cout << "\nExecuting 'mkdir' command to create a directory named '" << dirName << "':\n";
    system(("mkdir " + dirName).c_str());

    // 3. List the directory contents (ls)
    cout << "\nExecuting 'ls' command to list directory contents:\n";
    system("ls");

    // 4. Remove the directory (rmdir)
    cout << "\nExecuting 'rmdir' command to remove the directory named '" << dirName << "':\n";
    system(("rmdir " + dirName).c_str());

    // 5. List the directory contents again (ls)
    cout << "\nExecuting 'ls' command again to confirm removal:\n";
    system("ls");

    return 0;
}

// Executing 'pwd' command:
// /home/ifham/college-practical/OS/linux

// Executing 'mkdir' command to create a directory named 'test_directory':

// Executing 'ls' command to list directory contents:
// 17  17.cpp  test_directory

// Executing 'rmdir' command to remove the directory named 'test_directory':

// Executing 'ls' command again to confirm removal:
// 17  17.cpp