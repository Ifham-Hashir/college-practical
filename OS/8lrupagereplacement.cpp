//Aim: Write a program to demonstrate the use of LRU page replacement algorithm.

//Theory:The LRU (Least Recently Used) page replacement algorithm replaces the page that has not been used for the longest time when a page fault occurs. It ensures that the most recently accessed pages remain in memory while older pages are replaced.

#include <iostream>
using namespace std;

// Function to simulate the LRU page replacement algorithm
void lruPageReplacement(int frames[], int numFrames, int referenceString[], int numReferences) {
    int pageFaults = 0;

    // Iterate through the reference string
    for (int i = 0; i < numReferences; i++) {
        int currentPage = referenceString[i];
        bool pageInMemory = false;

        // Check if the page is already in memory
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == currentPage) {
                pageInMemory = true;
                // Move this page to the most recently used position
                for (int k = j; k > 0; k--) {
                    frames[k] = frames[k - 1]; // Shift pages forward
                }
                frames[0] = currentPage; // Place current page at the front
                break;
            }
        }

        // If the page is not in memory, it's a page fault
        if (!pageInMemory) {
            pageFaults++;

            // If there is space in the memory, insert the page
            for (int j = numFrames - 1; j > 0; j--) {
                frames[j] = frames[j - 1]; // Shift pages forward to make space
            }
            frames[0] = currentPage; // Place the new page at the front
        }

        // Print the current contents of memory (frame contents)
        cout << "Current memory state: ";
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == -1)
                cout << "Empty ";
            else
                cout << frames[j] << " ";
        }
        cout << endl;
    }

    cout << "\nTotal page faults: " << pageFaults << endl;
}

int main() {
    int numFrames; // Number of frames in memory
    cout << "Enter the number of frames in memory: ";
    cin >> numFrames;

    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3}; // Example reference string
    int numReferences = sizeof(referenceString) / sizeof(referenceString[0]);

    // Initialize frames with -1 to indicate empty slots
    int frames[numFrames];
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    // Call the LRU page replacement function
    lruPageReplacement(frames, numFrames, referenceString, numReferences);

    return 0;
}

// Output:
// Enter the number of frames in memory: 4
// Current memory state: 7 Empty Empty Empty 
// Current memory state: 0 7 Empty Empty 
// Current memory state: 1 0 7 Empty 
// Current memory state: 2 1 0 7 
// Current memory state: 0 2 1 7 
// Current memory state: 3 0 2 1 
// Current memory state: 0 3 2 1 
// Current memory state: 4 0 3 2 
// Current memory state: 2 4 0 3 
// Current memory state: 3 2 4 0 

// Total page faults: 6

//Conclusion: The LRU algorithm efficiently handles page faults by replacing the least recently used pages. It balances simplicity and effectiveness but may not always be the most optimal choice because it relies solely on past access patterns, which can lead to poor performance in some cases.