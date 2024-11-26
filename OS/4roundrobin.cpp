#include <iostream>
using namespace std;

void calculateWaitingTime(int bt[], int at[], int wt[], int tat[], int rem_bt[], int n, int tq) {
    int currentTime = 0;
    int completed = 0;

    // Loop until all processes are completed
    while (completed < n) {
        bool progressMade = false;

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                if (at[i] <= currentTime) {
                    // If process arrives and has remaining burst time
                    int timeToRun = (rem_bt[i] < tq) ? rem_bt[i] : tq;
                    rem_bt[i] -= timeToRun;
                    currentTime += timeToRun;

                    // If the process completes, calculate turnaround time and waiting time
                    if (rem_bt[i] == 0) {
                        tat[i] = currentTime - at[i];
                        wt[i] = tat[i] - bt[i];
                        completed++;
                    }
                    progressMade = true;
                }
            }
        }

        // If no process is making progress (should not happen unless there's a bug)
        if (!progressMade) {
            currentTime++;
        }
    }
}

void calculateAverageTimes(int wt[], int tat[], int n) {
    float totalWt = 0, totalTat = 0;

    for (int i = 0; i < n; i++) {
        totalWt += wt[i];
        totalTat += tat[i];
    }

    cout << "Average Waiting Time: " << totalWt / n << endl;
    cout << "Average Turnaround Time: " << totalTat / n << endl;
}

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], at[n], wt[n], tat[n], rem_bt[n];

    // Input burst time and arrival time for each process
    cout << "Enter burst time and arrival time for processes " <<endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i] >> at[i];
        rem_bt[i] = bt[i];  // Initialize remaining burst time
    }

    int tq;
    cout << "Enter time quantum: ";
    cin >> tq;

    // Calculate waiting time and turnaround time
    calculateWaitingTime(bt, at, wt, tat, rem_bt, n, tq);

    // Display process details
    cout << "\nProcess | Burst Time | Arrival Time | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t   " << bt[i] << "\t\t   " << at[i] 
              << "\t\t   " << wt[i] << "\t\t    " << tat[i] << endl;
    }

    // Calculate and display average waiting time and turnaround time
    calculateAverageTimes(wt, tat, n);

    return 0;
}


// Output:
// Enter number of processes: 3
// Enter burst time and arrival time for processes 
// P1: 10 0
// P2: 5 0
// P3: 8 0
// Enter time quantum: 4

// Process | Burst Time | Arrival Time | Waiting Time | Turnaround Time
// P1         10              0               13               23
// P2         5               0               12               17
// P3         8               0               13               21
// Average Waiting Time: 12.6667
// Average Turnaround Time: 20.3333