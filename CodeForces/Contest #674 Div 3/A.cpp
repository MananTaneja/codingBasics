#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int floor = 1;
        int flat = 2;
        while(flat < n) {
            floor++;
            flat += x;
        }
        cout << floor << endl;
    }
    return 0;
}