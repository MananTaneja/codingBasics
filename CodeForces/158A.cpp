#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int threshold;
    int count = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i == k - 1) {
            threshold = v[i];
        }
    }
    for(int num: v) {
        if(num >= threshold && num > 0) count++;
    }
    cout << count;
    return 0;
}