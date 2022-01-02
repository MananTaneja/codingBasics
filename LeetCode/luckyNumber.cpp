#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> matrix  = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    vector<int> V;
    vector<int> V2;
    for(auto x: matrix) {
        auto it = min_element(x.begin(), x.end());
        V.push_back(*it);
        V2.push_back(it - x.begin());
    }
    int col_number = 0;
    int rows = V.size();
    vector<int> V3 = V;
    for(int x: V3) {
        int max_ele = x;
        int col = V2[col_number];
        col_number++;
        for(int row = 0; row < rows; row++) {
            if(max_ele < matrix[row][col]) {
                remove(V.begin(), V.end(), max_ele);
                V.pop_back();
                break;
            }
        }
    }
}