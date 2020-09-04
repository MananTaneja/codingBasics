#include<bits/stdc++.h>
using namespace std;

bool f(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int countSwaps(vector<int>& arr) {
    vector<pair<int, int>> arrPos;
    for(int i = 0; i < arr.size(); i++) {
        arrPos.push_back({arr[i], i});
    }
    sort(arrPos.begin(), arrPos.end(), f);
    const int n = arr.size();
    vector<bool> visited(n, false);
    int count = 0;

    for(int i = 0; i < n; i++) {
        int current = arrPos[i].first;
        int prevIndex = arrPos[i].second;
        int curIndex = i;

        if(visited[i] || prevIndex == curIndex) continue;

        int cycleSize = 0;

        while(!visited[curIndex]) {
            visited[curIndex] = true;
            curIndex = prevIndex;
            cycleSize++;
        }

        count += max(cycleSize - 1, 0);
    }

    return count;
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int res = countSwaps(arr);

    cout << "Minimum number of swaps required is: " << res << endl;

    return 0;
}

/* {1, 5, 4, 3, 2}
    0, 1, 2, 3, 4

sorted - 1, 2, 3, 4, 5
         0, 1, 2, 3, 4


         2: 4 -> 1
         3: 3 -> 2
         4: 2 -> 3
         5: 1 -> 4


*/