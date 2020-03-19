#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> umap;
    int temp;
    for(int i = 0; i < 5; i++) {
        cin >> temp;
        umap[to_string(i)] = temp;
    }
    for(auto x: umap) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}