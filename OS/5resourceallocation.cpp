//Aim: Write a program to demonstrate the use of resource allocation to identify whether the system in in safe state.

// Theory: The Banker's Algorithm is a deadlock avoidance technique used in operating systems to ensure safe resource allocation. It determines whether the system is in a safe state by checking if all processes can complete their tasks using available and allocated resources without causing a deadlock.

#include <iostream>
using namespace std;

const int MAX_PROCESSES = 10; // Maximum number of processes
const int MAX_RESOURCES = 10; // Maximum number of resources

bool isSafe(int processes, int resources, int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES]) {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSequence[MAX_PROCESSES];

    // Initialize work as available
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    int count = 0;

    while (count < processes) {
        bool found = false;

        for (int p = 0; p < processes; p++) {
            if (!finish[p]) {
                bool canProceed = true;

                // Check if this process can proceed
                for (int r = 0; r < resources; r++) {
                    if (max[p][r] - allocation[p][r] > work[r]) {
                        canProceed = false;
                        break;
                    }
                }

                // If this process can proceed
                if (canProceed) {
                    for (int r = 0; r < resources; r++) {
                        work[r] += allocation[p][r];
                    }
                    safeSequence[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        // If no process could proceed, return false
        if (!found) {
            cout << "The system is not in a safe state.\n";
            return false;
        }
    }

    // If all processes could proceed, print the safe sequence
    cout << "The system is in a safe state.\nSafe sequence: ";
    for (int i = 0; i < processes; i++) {
        cout << "P" << safeSequence[i];
        if (i != processes - 1) cout << " -> ";
    }
    cout << endl;

    return true;
}

int main() {
    int processes, resources;

    cout << "Enter the number of processes: ";
    cin >> processes;

    cout << "Enter the number of resources: ";
    cin >> resources;

    int available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];

    cout << "Enter the available resources:\n";
    for (int i = 0; i < resources; i++) {
        cin >> available[i];
    }

    cout << "Enter the maximum resource matrix:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> max[i][j];
        }
    }

    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> allocation[i][j];
        }
    }

    isSafe(processes, resources, available, max, allocation);

    return 0;
}

// Output:
// Enter the number of processes: 5
// Enter the number of resources: 3
// Enter the available resources:
// 3 3 2
// Enter the maximum resource matrix:
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3
// Enter the allocation matrix:
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2
// The system is in a safe state.
// Safe sequence: P1 -> P3 -> P4 -> P0 -> P2

// Conclusion:The Banker's Algorithm ensures safe resource allocation by preventing deadlocks, but it requires prior knowledge of maximum resource needs, making it suitable only for predictable systems.