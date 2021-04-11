#include<bits/stdc++.h>

using namespace std;

// Program to find the sum of digits until single digit is being obtained



int main() {
    int n;
    cin >> n;
    if(n % 9 == 0) {
        cout << "9";
    }
    else {
        int rs = n % 9;
        cout << rs;
    }
    cout << endl;
}


