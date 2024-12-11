#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int> avail, vector<vector<int>> max, vector<vector<int>> alloc, vector<vector<int>> need, int n, int m) {
    vector<bool> done(n, false);
    for (int count = 0; count < n; ++count) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!done[i] && equal(need[i].begin(), need[i].end(), avail.begin(), less_equal<int>())) {
                for (int j = 0; j < m; ++j) avail[j] += alloc[i][j];
                done[i] = found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    int n, m;
    cout << "Processes: "; cin >> n;
    cout << "Resources: "; cin >> m;

    vector<int> avail(m);
    vector<vector<int>> max(n, vector<int>(m)), alloc(n, vector<int>(m)), need(n, vector<int>(m));

    cout << "Available: "; for (int &x : avail) cin >> x;
    cout << "Max: "; for (auto &row : max) for (int &x : row) cin >> x;
    cout << "Alloc: "; for (auto &row : alloc) for (int &x : row) cin >> x;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            need[i][j] = max[i][j] - alloc[i][j];

    if (isSafe(avail, max, alloc, need, n, m))
        cout << "System is safe.\n";
    else
        cout << "System is unsafe. Deadlock may occur.\n";

    return 0;
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

// System is safe.