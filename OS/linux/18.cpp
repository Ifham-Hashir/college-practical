#include <iostream>
#include <cstdlib> // For system()

using namespace std;

int main() {
    string fileName = "test_file.txt";
    string copiedFileName = "copied_file.txt";

    // 1. Create a new file (touch)
    cout << "\nExecuting 'touch' command to create a file named '" << fileName << "':\n";
    system(("touch " + fileName).c_str());

    // 2. Write content to the file using echo and display using cat
    cout << "\nWriting 'Hello, World!' to the file and displaying it using 'cat':\n";
    system(("echo 'Hello, World!' > " + fileName).c_str());
    system(("cat " + fileName).c_str());

    // 3. Copy the file to a new file (cp)
    cout << "\nExecuting 'cp' command to copy the file to '" << copiedFileName << "':\n";
    system(("cp " + fileName + " " + copiedFileName).c_str());

    // 4. List files to confirm the copy
    cout << "\nListing files to confirm both files exist:\n";
    system("ls");

    // 5. Remove both files (rm)
    cout << "\nExecuting 'rm' command to delete both files:\n";
    system(("rm " + fileName + " " + copiedFileName).c_str());

    // 6. List files to confirm removal
    cout << "\nListing files again to confirm removal:\n";
    system("ls");

    return 0;
}

// Executing 'touch' command to create a file named 'test_file.txt':

// Writing 'Hello, World!' to the file and displaying it using 'cat':
// Hello, World!

// Executing 'cp' command to copy the file to 'copied_file.txt':

// Listing files to confirm both files exist:
// 17  17.cpp  18  18.cpp  copied_file.txt  test_file.txt

// Executing 'rm' command to delete both files:

// Listing files again to confirm removal:
// 17  17.cpp  18  18.cpp