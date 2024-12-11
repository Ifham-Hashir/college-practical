#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <unistd.h>

int main() {
    // Generate a unique key
    key_t key = ftok("shmfile", 65);

    // Create shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach to the shared memory
    char *str = (char*) shmat(shmid, (void*)0, 0);

    while (true) {
        // Write to shared memory
        std::cout << "Enter data to write (or type 'exit' to quit): ";
        std::cin.getline(str, 1024);

        if (strcmp(str, "exit") == 0) break;

        // Simulate another process reading the data
        std::cout << "Data read from memory: " << str << std::endl;
    }

    // Detach from shared memory
    shmdt(str);

    // Destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

// Enter data to write (or type 'exit' to quit): SGBAU
// Data read from memory: SGBAU
// Enter data to write (or type 'exit' to quit): exit
