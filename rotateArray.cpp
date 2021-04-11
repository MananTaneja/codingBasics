#include<bits/stdc++.h>
using namespace std;


int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    if(k == 0 || nums.size() <= 1) {
        for(int x: nums) {
            cout << x;
        }
        return 1;
    }
    int n = nums.size();
    int temp1 = nums[0];
    int targ = k%n;
    while(n--) {
        int temp2 = nums[targ];
        nums[targ] = temp1;
        temp1 = temp2;
        targ = (targ+k) % nums.size();       
    }
    for(int x: nums) {
        cout << x << " ";
    }
    return 0;
}