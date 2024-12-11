#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> dir;

void createFile(string f) {
    if (find(dir.begin(), dir.end(), f) != dir.end()) 
        cout << "File exists!\n";
    else {
        dir.push_back(f);
        cout << "File created.\n";
    }
}

void deleteFile(string f) {
    auto it = find(dir.begin(), dir.end(), f);
    if (it != dir.end()) {
        dir.erase(it);
        cout << "File deleted.\n";
    } else 
        cout << "File not found!\n";
}

void listFiles() {
    if (dir.empty()) cout << "Directory empty.\n";
    else for (auto &f : dir) cout << f << "\n";
}

int main() {
    int ch;
    string f;
    while (true) {
        cout << "1.Create 2.Delete 3.List 4.Exit: "; cin >> ch;
        if (ch == 4) break;
        cout << "File: "; cin >> f;
        if (ch == 1) createFile(f);
        else if (ch == 2) deleteFile(f);
        else listFiles();
    }
}

// 1.Create 2.Delete 3.List 4.Exit: 1
// File: OS
// File created.
// 1.Create 2.Delete 3.List 4.Exit: 4