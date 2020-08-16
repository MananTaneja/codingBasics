#include <bits/stdc++.h>
using namespace std;

long long int M = 1e9 + 7;
long long unsigned res = 0;

void helper(int x, int y, int z, int n)
{

    res = (res + n % M) % M;

    if (x > 0)
    {
        helper(x - 1, y, z, (10 * n) % M + 4);
    }
    if (y > 0)
    {
        helper(x, y - 1, z, (10 * n) % M + 5);
    }
    if (z > 0)
    {
        helper(x, y, z - 1, (10 * n) % M + 6);
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        helper(x, y, z, 0);
        cout << res << endl;
        res = 0;
    }
    return 0;
}
