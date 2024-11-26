// Write a program to demonstrate the use of FCFS CPU Scheduling algorithm.

#include<iostream>
using namespace std;


void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
  // waiting time for first process is 0
  wt[0] = 0;

    // calculating waiting time
  for (int  i = 1; i < n ; i++ )
    wt[i] =  bt[i-1] + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
  // calculating turnaround time by adding bt[i] + wt[i]
  for (int  i = 0; i < n ; i++)
    tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findAvgTime( int processes[], int n, int bt[])
{
  int wt[n], tat[n], total_wt = 0, total_tat = 0;

  //Function to find waiting time of all processes
  findWaitingTime(processes, n, bt, wt);

  //Function to find turn around time for all processes
  findTurnAroundTime(processes, n, bt, wt, tat);

  //Display processes along with all details
  cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";

  // Calculate total waiting time and total turn around time
  for (int  i=0; i<n; i++)
  {
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
  }

    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}


int main()
{
  int n;
  cout << "Enter the number of processes: ";
  cin  >> n;

  int processes[n];
  for(int i = 0; i < n; i++){
    processes[i] = i+1;
  }
  
  int burst_time[n];
  for(int i = 0; i < n; i++){
    cout << "Enter burst time for process " << i+1 << ":";
    cin >> burst_time[i];
  }

  findAvgTime(processes, n,  burst_time);
  return 0;
}

// Output
// Enter the number of processes: 3
// Enter burst time for process 1:10
// Enter burst time for process 2:5
// Enter burst time for process 3:8
// Processes   Burst time   Waiting time   Turn around time
//    1            10          0             10
//    2            5           10            15
//    3            8           15            23
// Average waiting time = 8.33333
// Average turn around time = 16