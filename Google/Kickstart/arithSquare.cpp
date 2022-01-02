#include<bits/stdc++.h>
using namespace std;

bool checkAP(vector<int>& row) {
    int d1 = row[1] - row[0];
    int d2 = row[2] - row[1];

    if(d1 == d2) return true;
    return false;
}

int missingCheckAP(vector<int>& row) {
    int d = row[2] - row[0];
    if(d % 2 != 0) return INT_MIN;
    else return row[2] - d/2;
}

int main() {
    const int r = 3;
    const int c = 3;
    int t;
    cin >> t;

    while(t--) {
        unordered_map<int, int> occ;
        vector<vector<int>> arr(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(i == 1 && j == 1) continue;
                cin >> arr[i][j];
            }
        }

        vector<int> row = arr[1];
        vector<int> col1;
        vector<int> col2;
        vector<int> col3;
        vector<int> d1;
        vector<int> d2;

        int count = 0;

        count += checkAP(arr[0]);
        count += checkAP(arr[2]);
        // cout << "Interim Count: " << count << endl;
        for(int i = 0; i < r; i++) {
            col1.push_back(arr[i][0]);
            col2.push_back(arr[i][1]);
            col3.push_back(arr[i][2]);
        }

        count += checkAP(col1);
        count += checkAP(col3);
        // cout << "Interim Count: " << count << endl; 
        for(int i = 0; i < r; i++) {
            d1.push_back(arr[i][i]);
            d2.push_back(arr[i][r-i-1]);
        }

        // row, col2, d1, d2

        int a1 = missingCheckAP(row);
        if(a1 != INT_MIN) {
            occ[a1]++;
        }
        a1 = missingCheckAP(col2);
        if(a1 != INT_MIN) {
            occ[a1]++;
        }
        a1 = missingCheckAP(d1);
        if(a1 != INT_MIN) {
            occ[a1]++;
        }
        a1 = missingCheckAP(d2);
        if(a1 != INT_MIN) {
            occ[a1]++;
        }

        // cout << "Interim Count: " << count << endl;

        int maxOcc = 0;
        
        for(auto it = occ.begin(); it != occ.end(); it++) {
            if(it->second > maxOcc) {
                maxOcc = it->second;
            }
        }

        count += maxOcc;

        cout << count << endl;
    }


    return 0;
}