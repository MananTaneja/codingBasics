#include<bits/stdc++.h>
using namespace std;

int n = 5;
char A[5];

void binary(int n) {
    if(n<1) {
        printf("%s", A);
    }
    else {
        A[n-1] = 0;
        binary(n-1);
        A[n-1] = 1;
        binary(n-1); 
    }
}

int main() {
    binary(5);
    return 0;
}