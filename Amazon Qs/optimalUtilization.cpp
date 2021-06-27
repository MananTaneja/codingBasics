#include<bits/stdc++.h>
using namespace std;

bool c(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> a = {{1, 8}, {2, 15}, {3, 9}};
    vector<pair<int, int>> b = {{1, 8}, {2, 11}, {3, 12}};
    vector<pair<int, int>> res; 

    int target = 20;

    sort(a.begin(), a.end(), c);
    sort(b.begin(), b.end(), c);

    int i = 0, j = b.size()-1;
    int closest = INT_MIN;

    while(i < a.size() && j >= 0) {
        int curSum = a[i].second + b[j].second;

        if(curSum > target) {
            j--;
        }

        else {
            if(curSum > closest) {
                closest = curSum;
                res = {{a[i].first, b[j].first}};
            }
            else if(curSum == closest){
                res.push_back({a[i].first, b[j].second});
            }
            i++;
        }
    }

    cout << closest << endl;

    for(auto p: res) {
        cout << p.first << " " << p.second << endl; 
    }

    return 0;
}