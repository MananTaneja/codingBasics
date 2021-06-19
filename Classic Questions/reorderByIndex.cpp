#include<bits/stdc++.h>
using namespace std;


void do_swaps(vector<int>& A, vector<int>& B, int i, int n) {
    int curVal = A[i];
    int newPosition = B[B[i]-1];

    while(newPosition <= n) {
        int correctIndex = B[i] - 1;
        int temp = A[correctIndex];
        curVal = temp;
        B[i] += n;
        newPosition = B[correctIndex];
        i = correctIndex;
    }
}


void sortCorrect(vector<int>& A, vector<int>& B) {
    for(int i = 0; i < A.size(); i++) {
        if(B[i] - 1 == i) {
            B[i] += A.size();
        }
        else if(B[i] <= A.size()) {
            do_swaps(A, B, i, A.size());
        }
    }
}


int main() {
    vector<int> a = {24, 56, 74, -23, 87, 91};
    vector<int> b = {2, 3, 4, 1, 5, 6};

    sortCorrect(a, b);

    for(int num: a) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}