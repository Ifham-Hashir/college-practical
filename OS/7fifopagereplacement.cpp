//Aim: Write a program to demonstrate the use of FIFO page replacement algorithm.

//Theory: The FIFO (First-In-First-Out) page replacement algorithm replaces the oldest page in memory when a new page needs to be loaded, ensuring that the first page to enter memory is the first to be replaced. This algorithm is simple but can suffer from high page fault rates in some scenarios.

#include <iostream>
using namespace std;

// Function to simulate the FIFO page replacement algorithm
void fifoPageReplacement(int frames[], int numFrames, int referenceString[], int numReferences) {
    int pageFaults = 0;
    int front = 0; // To simulate a queue (FIFO behavior)
    bool pageInMemory;

    // Iterate through the reference string
    for (int i = 0; i < numReferences; i++) {
        int currentPage = referenceString[i];
        pageInMemory = false;

        // Check if the page is already in memory
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == currentPage) {
                pageInMemory = true;
                break;
            }
        }

        // If the page is not in memory, it's a page fault
        if (!pageInMemory) {
            pageFaults++;

            // If there is space in the memory, insert the page
            if (frames[front] == -1) {
                frames[front] = currentPage;
            } else {
                // If memory is full, replace the oldest page (FIFO)
                frames[front] = currentPage;
            }

            // Move the front pointer to the next position (circular queue behavior)
            front = (front + 1) % numFrames;
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

    // Call the FIFO page replacement function
    fifoPageReplacement(frames, numFrames, referenceString, numReferences);

    return 0;
}

// Output: 
// Enter the number of frames in memory: 3
// Current memory state: 7 Empty Empty 
// Current memory state: 7 0 Empty 
// Current memory state: 7 0 1 
// Current memory state: 2 0 1 
// Current memory state: 2 0 1 
// Current memory state: 2 3 1 
// Current memory state: 2 3 0 
// Current memory state: 4 3 0 
// Current memory state: 4 2 0 
// Current memory state: 4 2 3 

// Total page faults: 9

//Conclusion: The FIFO page replacement algorithm is easy to implement and provides a straightforward approach to managing memory, though it may not always be the most efficient in minimizing page faults.