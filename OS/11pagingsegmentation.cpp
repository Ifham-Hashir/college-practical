//Aim: Write a program to simulate the paging technique segmentation technique of memory management.

// Theory: Paging divides memory into fixed-size pages and maps them to frames using a page table, allowing non-contiguous allocation. Segmentation, on the other hand, divides memory based on logical divisions like functions or arrays, with each segment having its own base address and size, allowing variable-sized allocation.

#include <iostream>
#include <vector>
using namespace std;

// Function to simulate the Paging technique
void simulatePaging(int num_pages, int page_size) {
    int page_table[100];  // Page table to map pages to frames
    int logical_address;
    int page_no, offset;

    // Taking frame numbers for each page
    cout << "\nEnter the frame numbers for each page:\n";
    for (int i = 0; i < num_pages; i++) {
        cout << "Enter the frame number for page " << i << ": ";
        cin >> page_table[i];
    }

    // Displaying the page table
    cout << "\nPage Table:\n";
    cout << "Page No.\tFrame No.\n";
    for (int i = 0; i < num_pages; i++) {
        cout << i << "\t\t" << page_table[i] << endl;
    }

    // Simulating the paging technique
    cout << "\nEnter the logical address: ";
    cin >> logical_address;

    // Calculating page number and offset
    page_no = logical_address / page_size;
    offset = logical_address % page_size;

    cout << "Page Number: " << page_no << ", Offset: " << offset << endl;
    cout << "Frame Number: " << page_table[page_no] << ", Physical Address: "
         << page_table[page_no] * page_size + offset << endl;
}

// Function to simulate the Segmentation technique
void simulateSegmentation(int num_segments) {
    int segment_table[100];  // Segment table to map segments to their base addresses
    int logical_address;
    int segment_no, offset;

    // Taking base addresses for each segment
    cout << "\nEnter the base addresses for each segment:\n";
    for (int i = 0; i < num_segments; i++) {
        cout << "Enter the base address for segment " << i << ": ";
        cin >> segment_table[i];
    }

    // Displaying the segment table
    cout << "\nSegment Table:\n";
    cout << "Segment No.\tBase Address\n";
    for (int i = 0; i < num_segments; i++) {
        cout << i << "\t\t" << segment_table[i] << endl;
    }

    // Simulating the segmentation technique
    cout << "\nEnter the logical address: ";
    cin >> logical_address;

    // Calculating segment number and offset
    segment_no = logical_address / 1000;  // Assuming segment size is 1000 units
    offset = logical_address % 1000;

    cout << "Segment Number: " << segment_no << ", Offset: " << offset << endl;
    cout << "Base Address: " << segment_table[segment_no] << ", Physical Address: "
        << segment_table[segment_no] + offset << endl;
}

int main() {
    int choice;

    // Displaying options for paging or segmentation
    cout << "Choose the memory management technique:\n";
    cout << "1. Paging\n2. Segmentation\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        int num_pages, page_size;
        cout << "Enter the number of pages: ";
        cin >> num_pages;
        cout << "Enter the size of each page: ";
        cin >> page_size;

        simulatePaging(num_pages, page_size);
    } else if (choice == 2) {
        int num_segments;
        cout << "Enter the number of segments: ";
        cin >> num_segments;

        simulateSegmentation(num_segments);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

// Choose the memory management technique:
// 1. Paging
// 2. Segmentation
// Enter choice: 2
// Enter the number of segments: 3

// Enter the base addresses for each segment:
// Enter the base address for segment 0: 1000
// Enter the base address for segment 1: 2000
// Enter the base address for segment 2: 3000

// Segment Table:
// Segment No.     Base Address
// 0               1000
// 1               2000
// 2               3000

// Enter the logical address: 2500
// Segment Number: 2, Offset: 500
// Base Address: 3000, Physical Address: 3500

// Output2:
// Enter choice: 1
// Enter the number of pages: 4
// Enter the size of each page: 100

// Enter the frame numbers for each page:
// Enter the frame number for page 0: 2
// Enter the frame number for page 1: 5
// Enter the frame number for page 2: 7
// Enter the frame number for page 3: 3

// Page Table:
// Page No.        Frame No.
// 0               2
// 1               5
// 2               7
// 3               3

// Enter the logical address: 205
// Page Number: 2, Offset: 5
// Frame Number: 7, Physical Address: 705

// Conclusion: Paging and segmentation are both memory management techniques that help in efficient memory utilization. While paging uses fixed-size blocks for allocation, segmentation allows for more flexible, logical divisions of memory.