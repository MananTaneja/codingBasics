#include<bits/stdc++.h>
using namespace std;


int main() {
    vector<int> A = {2, 1 , 3, 5, 4};
    // int moment = -1;
    // bool left = false;
    // bool check = false;
    // int n = light.size();
    // vector<int> bulb = {};
    // bulb.assign(n ,-1);
    // int count = 0;
    // for(int x: light) {
    //     moment++;
    //     if(x == 1) {
    //         bulb[0] = 1;
    //         check =  true;
    //     }
    //     else {
    //         bulb[x-1] = 0;
    //     }
    //     bool left = true;
    //     if(check) {
    //         for(int i = 1; i < bulb.size(); i++) {
    //             if(i==1 && bulb[i] == 0) {
    //                 bulb[i] = 1;
    //             }
    //             else if(bulb[i] == 0 && left) {
    //                 bulb[i] = 1;
    //             }
    //             else if(bulb[i] == -1){
    //                 left = false;
    //                 break;
    //             }
    //             else {

    //             }
    //         }
    //     }
    //     bool zero = true;
    //     for(int y: bulb) {
    //         if(y==0) {
    //             zero = false;
    //             break;
    //         }
    //     }
    //     if(zero){
    //         count++;
    //     }
        
    // }
    // cout << count << endl; 

    int right = 0, res = 0, n = A.size();
        for (int i = 0; i < n; ++i){
            right = max(right, A[i]);
            if(right == i + 1) {
                res++;
            }
        }
        cout << res;     
}