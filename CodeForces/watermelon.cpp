#include<bits/stdc++.h>
using namespace std;

int main() {
    int w;
    cin >> w;
    bool res = false;
    for(int i = 1; i < w; i++) {
        int first = i;
        int second = w - i;

        if(first % 2 == 0 && second % 2 == 0) {
            res = true;
            cout << "YES";
            break;
        }
    }

    if(!res) cout << "NO";
    
    return 0;
}