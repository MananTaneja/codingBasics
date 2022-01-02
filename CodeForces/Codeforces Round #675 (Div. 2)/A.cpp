#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c;
        d = 0;
        if (a + c + d <= b)
        {
            d += (b - (a + c + d)) + 1;
        }
        if (b + c + d <= a)
        {
            d += a - (b + c + d) + 1;
        }
        if (a + b + d <= c)
        {
            d += c - (a + b + d) + 1;
        }
        if (d >= a + b + c)
        {
            d -= d - (a + b + c) - 1;
        }
        cout << d << endl;
    }
    return 0;
}