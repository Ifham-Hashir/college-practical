// Write a program to implement the producer-consumer problem using semaphores.

//Theory: The Producer-Consumer problem demonstrates synchronization between processes sharing a fixed-size buffer, ensuring producers don’t overfill and consumers don’t access an empty buffer by using semaphores for mutual exclusion and resource tracking.

//Example:
// Initial Buffer:
// [   ,   ,   ,   ,   ]  (Empty slots)

// Step 1: Producer produces item 1
// [ 1 ,   ,   ,   ,   ]  (1 item in buffer)

// Step 2: Consumer consumes item 1
// [   ,   ,   ,   ,   ]  (Buffer empty)

// Step 3: Producer produces item 2
// [ 2 ,   ,   ,   ,   ]  (1 item in buffer)

// Step 4: Producer produces item 3
// [ 2 , 3 ,   ,   ,   ]  (2 items in buffer)

// Step 5: Consumer consumes item 2
// [   , 3 ,   ,   ,   ]  (1 item in buffer)


#include <iostream>
#include <thread>
#include <semaphore.h>
#include <chrono>

using namespace std;

const int BUFFER_SIZE = 5; // Maximum buffer size
int buffer[BUFFER_SIZE];   // Shared buffer implemented as an array
int in = 0, out = 0;       // Pointers for producer (in) and consumer (out)

sem_t emptySlots;          // Semaphore to count empty slots
sem_t fullSlots;           // Semaphore to count full slots
sem_t mutex;               // Semaphore for mutual exclusion

void producer(int id) {
    for (int i = 1; i <= 3; i++) { // Produces 3 items
        sem_wait(&emptySlots); // Wait if the buffer is full
        sem_wait(&mutex);      // Lock the critical section

        // Produce an item
        buffer[in] = i;
        cout << "Producer " << id << " produced item " << i << " at index " << in << endl;
        in = (in + 1) % BUFFER_SIZE; // Circular buffer logic

        sem_post(&mutex);      // Unlock the critical section
        sem_post(&fullSlots);  // Signal that an item is produced

        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate production time
    }
}

void consumer(int id) {
    for (int i = 1; i <= 3; i++) { // Consumes 3 items
        sem_wait(&fullSlots); // Wait if the buffer is empty
        sem_wait(&mutex);     // Lock the critical section

        // Consume an item
        int item = buffer[out];
        cout << "Consumer " << id << " consumed item " << item << " from index " << out << endl;
        out = (out + 1) % BUFFER_SIZE; // Circular buffer logic

        sem_post(&mutex);     // Unlock the critical section
        sem_post(&emptySlots); // Signal that an item is consumed

        this_thread::sleep_for(chrono::milliseconds(150)); // Simulate consumption time
    }
}

int main() {
    // Initialize semaphores
    sem_init(&emptySlots, 0, BUFFER_SIZE); // Initially, buffer is empty
    sem_init(&fullSlots, 0, 0);            // Initially, no items in buffer
    sem_init(&mutex, 0, 1);                // Mutex initialized to 1

    // Create producer and consumer threads
    thread producerThread1(producer, 1);
    thread consumerThread1(consumer, 1);

    // Wait for threads to finish
    producerThread1.join();
    consumerThread1.join();

    // Destroy semaphores
    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    sem_destroy(&mutex);

    return 0;
}

// Output: 
// Producer 1 produced item 1 at index 0
// Consumer 1 consumed item 1 from index 0
// Producer 1 produced item 2 at index 1
// Consumer 1 consumed item 2 from index 1
// Producer 1 produced item 3 at index 2
// Consumer 1 consumed item 3 from index 2

// Conclusion: 
// The Producer-Consumer problem demonstrates efficient synchronization using semaphores to manage shared resources, ensuring that producers and consumers operate without conflicts while maintaining a stable buffer state.