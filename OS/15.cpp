#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Processes: "; cin >> n;
    cout << "Resource types: "; cin >> m;

    vector<int> available(m);
    vector<vector<int>> max(n, vector<int>(m)), alloc(n, vector<int>(m)), need(n, vector<int>(m));
    vector<bool> finished(n, false);

    cout << "Available: "; for (int &x : available) cin >> x;
    cout << "Max matrix:\n"; for (auto &row : max) for (int &x : row) cin >> x;
    cout << "Allocation matrix:\n"; for (auto &row : alloc) for (int &x : row) cin >> x;

    // Calculate Need matrix
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            need[i][j] = max[i][j] - alloc[i][j];

    vector<int> safeSeq;
    for (int count = 0; count < n; ++count) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!finished[i]) {
                bool canAlloc = true;
                for (int j = 0; j < m; ++j)
                    if (need[i][j] > available[j]) { canAlloc = false; break; }
                if (canAlloc) {
                    for (int j = 0; j < m; ++j) available[j] += alloc[i][j];
                    safeSeq.push_back(i);
                    finished[i] = true;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << "System is in an unsafe state.\n";
            return 0;
        }
    }
    cout << "Safe sequence: ";
    for (int p : safeSeq) cout << "P" << p << " ";
    cout << endl;
}

// Processes: 5  
// Resources: 3  

// Available: 3 3 2  

// Max:  
// 7 5 3  
// 3 2 2  
// 9 0 2  
// 2 2 2  
// 4 3 3  

// Alloc:  
// 0 1 0  
// 2 0 0  
// 3 0 2  
// 2 1 1  
// 0 0 2  

// Safe sequence: P1 P3 P0 P2 P4