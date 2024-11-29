//Aim: Write a program to demonstrate the use of SCAN disk scheduling algorithm.

// Theory: The SCAN disk scheduling algorithm moves the disk head in one direction, servicing requests until it reaches the end, then reverses direction to service remaining requests. This approach minimizes seek time and reduces starvation compared to FCFS.

//Example:
//Disk requests: 98, 183, 37, 122, 14, 124, 65, 67
// Initial head position: 53
// Disk size: 200
// Initial direction: right
// Execution:
// Separate requests into left and right:

// Left: {37, 14}
// Right: {65, 67, 98, 122, 124, 183}
// Sort both sides:

// Left: {14, 37}
// Right: {65, 67, 98, 122, 124, 183}
// Head moves to the right, then reverses:

// Seek sequence: 65 → 67 → 98 → 122 → 124 → 183 → 199 → 37 → 14
// Output:
// Seek Sequence: 65, 67, 98, 122, 124, 183, 199, 37, 14
// Total Seek Operations: 331

#include <iostream>
#include <algorithm>
using namespace std;

void SCAN(int arr[], int n, int head, int disk_size, string direction) {
    int seek_count = 0;       // Total number of seek operations
    int distance, cur_track; // Distance and the current track being serviced
    int seek_sequence[100];  // To store the seek sequence
    int index = 0;

    // Create arrays for requests on left and right of the head
    int left[100], right[100];
    int left_count = 0, right_count = 0;

    // Separate requests into left and right based on head position
    for (int i = 0; i < n; i++) {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        else
            right[right_count++] = arr[i];
    }

    // Sort the left and right arrays
    sort(left, left + left_count);
    sort(right, right + right_count);

    // SCAN Algorithm: Service requests in the direction of the initial movement
    if (direction == "right") {
        // Service the right side first
        for (int i = 0; i < right_count; i++) {
            cur_track = right[i];
            seek_sequence[index++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
        // After reaching the rightmost end, go to the leftmost end
        seek_count += abs(disk_size - 1 - head);
        head = disk_size - 1;

        for (int i = left_count - 1; i >= 0; i--) {
            cur_track = left[i];
            seek_sequence[index++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
    } else if (direction == "left") {
        // Service the left side first
        for (int i = left_count - 1; i >= 0; i--) {
            cur_track = left[i];
            seek_sequence[index++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
        // After reaching the leftmost end, go to the rightmost end
        seek_count += abs(head - 0);
        head = 0;

        for (int i = 0; i < right_count; i++) {
            cur_track = right[i];
            seek_sequence[index++] = cur_track;
            distance = abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
    }

    // Print the results
    cout << "Seek Sequence: ";
    for (int i = 0; i < index; i++) {
        cout << seek_sequence[i] << " ";
    }
    cout << endl;
    cout << "Total Seek Operations: " << seek_count << endl;
}

int main() {
    int n, head, disk_size;
    string direction;

    // Input from user
    cout << "Enter the number of requests: ";
    cin >> n;
    int arr[100];
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    cout << "Enter the disk size: ";
    cin >> disk_size;

    cout << "Enter the initial direction (right or left): ";
    cin >> direction;

    // Call SCAN function
    SCAN(arr, n, head, disk_size, direction);

    return 0;
}

//Output: 
// Enter the number of requests: 8
// Enter the requests: 98 183 37 122 14 124 65 67
// Enter the initial head position: 53
// Enter the disk size: 200
// Enter the initial direction (right or left): right
// Seek Sequence: 65 67 98 122 124 183 37 14 
// Total Seek Operations: 331

// Conclusion: The SCAN algorithm efficiently handles disk scheduling by minimizing head movement and balancing request servicing in both directions. However, it may still cause delays for requests near the edges of the disk.