#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        bool even = true;
        bool odd = true;
        int n;
        cin >> n;
        vector<int> V;
        for(int i = 0 ;i < n; i++) {
            int temp;
            cin >> temp;
            V.push_back(temp);
        }
        for(int x: V) {
            if(x % 2 != 0) {
                even = false;
                break;
            }
        }
        for(int x: V) {
            if(x % 2 == 0) {
                odd = false;
                break;
            }
        }
        if(even || odd) {
            cout << "Yes"<<endl;
        } 
        else {
            cout << "No"<<endl;
        }
    }
    return 0;
}