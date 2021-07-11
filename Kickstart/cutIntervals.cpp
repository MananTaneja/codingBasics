#include<bits/stdc++.h>
using namespace std;

void overlapCount() {

}

bool f(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int t; 
    cin >> t;

    while(t--) {
        int c, n;
        cin >> n >> c;
        vector<pair<int, int>> intervals(n);
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            intervals.push_back({l, r});
        }
        sort(intervals.begin(), intervals.end(), f);
        int count = 0;

        while(c--) {
            vector<pair<int, int>> nextIntervals;

            for(int i = 0; i < intervals.size()-1; i++) {
                
            } 
        }

    }
}