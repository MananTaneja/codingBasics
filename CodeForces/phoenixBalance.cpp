#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int sum1 = pow(2, n);
        int sum2 = 0;
        int a = 1;
        int b = 0;
        int l = n - 1;
        while(b != n/2 && l > 0)  {
            b++;
            sum1 = abs(sum1 - pow(2, l--));
        }
        while(a != n/2 && l > 0) {
            a++;
            sum1 += pow(2, l--);
        }
        cout << sum1 << endl; 
    }

    return 0;
}