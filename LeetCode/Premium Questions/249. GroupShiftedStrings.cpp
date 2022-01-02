#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupShiftedStrings(vector<string>& inp) {
    
}


int main() {
    vector<string> inp = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> ans = groupShiftedStrings(inp);
    for(auto x: ans) {
        cout << "[";
        for(auto y: x) {
            cout << y << ", ";
        }
        cout << "]\n";
    }

    return 0;
}

