#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int counter = 0;           // Shared resource
mutex mtx;            // Mutex for synchronization

// Function to increment the counter
void increment(int id) {
    for (int i = 0; i < 2; ++i) {
        lock_guard<mutex> lock(mtx);  // Lock the mutex
        ++counter;
        cout << "Thread " << id << " incremented counter to " << counter << endl;
    }
}

int main() {
    // Create threads
    thread t1(increment, 1);
    thread t2(increment, 2);

    // Join threads to the main thread
    t1.join();
    t2.join();

    cout << "Final Counter Value: " << counter << endl;
    return 0;
}

// Thread 1 incremented counter to 1
// Thread 1 incremented counter to 2
// Thread 2 incremented counter to 3
// Thread 2 incremented counter to 4
// Final Counter Value: 4