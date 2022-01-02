#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<int> V;
        bool isPal = false;
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            int temp;
            cin >> temp;
            V.push_back(temp);
        }
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 2; j < n; j++) { 
            if(V[i] == V[j]) {
                isPal = true;
                }
            }
        }
        if(isPal == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}