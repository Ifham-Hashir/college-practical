//Aim: Write a program to demonstrate the use of deadlock detection algorithm.

//Theory: Deadlock detection is a method to identify whether processes in a system are stuck in a circular wait, preventing further execution. It uses algorithms like wait-for graphs to detect cycles indicating deadlocks.

#include <iostream>
using namespace std;

class DeadlockDetector {
public:
    // Function to detect deadlock
    bool detectDeadlock(int waitForGraph[][10], int numProcesses) {
        int visited[10] = {0}; // 0 = unvisited, 1 = visiting, 2 = visited
        
        // Check for deadlock in each process
        for (int i = 0; i < numProcesses; i++) {
            if (visited[i] == 0) {
                if (isDeadlock(i, waitForGraph, visited, numProcesses)) {
                    return true; // Deadlock detected
                }
            }
        }
        return false; // No deadlock
    }

private:
    // Helper function to perform DFS and detect cycles
    bool isDeadlock(int process, int graph[][10], int visited[], int numProcesses) {
        // Mark the current process as visiting (part of the recursion stack)
        visited[process] = 1;

        // Explore all neighbors (i.e., processes that this process is waiting for)
        for (int i = 0; i < numProcesses; i++) {
            if (graph[process][i] == 1) {  // If there is a waiting edge
                if (visited[i] == 1) {
                    return true; // Cycle detected (deadlock)
                }
                if (visited[i] == 0 && isDeadlock(i, graph, visited, numProcesses)) {
                    return true;
                }
            }
        }

        // Mark the process as visited (no deadlock in this path)
        visited[process] = 2;
        return false;
    }
};

int main() {
    int numProcesses, numResources;
    cout << "Enter number of processes: ";
    cin >> numProcesses;
    cout << "Enter number of resources: ";
    cin >> numResources;

    // Create a 2D array to represent the wait-for graph
    // waitForGraph[i][j] = 1 means process i is waiting for process j
    int waitForGraph[10][10] = {0};

    cout << "Enter the wait-for graph (pairs of processes where one is waiting for the other): \n";
    cout << "For example, if process 0 is waiting for process 1, enter 0 1.\n";

    int p1, p2;
    while (true) {
        cout << "Enter pair (enter -1 -1 to stop): ";
        cin >> p1 >> p2;
        if (p1 == -1 && p2 == -1) break;
        waitForGraph[p1][p2] = 1; // Process p1 is waiting for process p2
    }

    DeadlockDetector detector;
    if (detector.detectDeadlock(waitForGraph, numProcesses)) {
        cout << "Deadlock detected!" << endl;
    } else {
        cout << "No deadlock detected!" << endl;
    }

    return 0;
}

// Output:
// Enter number of processes: 4
// Enter number of resources: 3
// Enter the wait-for graph (pairs of processes where one is waiting for the other): 
// For example, if process 0 is waiting for process 1, enter 0 1.
// Enter pair (enter -1 -1 to stop): 0 1
// Enter pair (enter -1 -1 to stop): 1 2
// Enter pair (enter -1 -1 to stop): 2 0
// Enter pair (enter -1 -1 to stop): -1 -1
// Deadlock detected!


// Conclusion: Deadlock detection helps identify and resolve deadlocks by detecting circular waits among processes. It ensures system stability by enabling corrective actions like process termination or resource preemption.