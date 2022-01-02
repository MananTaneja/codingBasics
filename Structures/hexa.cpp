
#include <bits/stdc++.h>
using namespace std;

#define MAXI (int)(1e8)


vector<int> v;

void precompute(int a, int b)
{

    int x = 1, y = 1;
    while (x <= MAXI)
    {
        while (x * y <= MAXI)
        {
            v.push_back(x * y);

         
            y *= b;
        }


        x *= a;

        y = 1;
    }


    sort(v.begin(), v.end());
}


void countNum(int r)
{
    
    int ans  = upper_bound(v.begin(), v.end(), r) - v.begin();
    cout << --ans << endl;
}

int main()
{   
    int n;
    cin >> n;
    int r = INT_MIN;
    int a, b;
    cin >> a >> b;

    precompute(a, b);

    vector<int> vec;

    for(int i = 0; i < n; i++) {
        int temp; 
        cin >> temp;
        vec.push_back(temp);
    }
    
    for(int num: vec) {
        countNum(num);
    }

    return 0;
}
