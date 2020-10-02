#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int day = 0;
        vector<int> q(n);
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        int i;
        for (i = 0; i < n; i++)
        {
            if (q[i] >= k)
            {
                day++;
                q[i + 1] += (q[i] - k);
            }
            else
            {
                break;
            }
        }
        if (i == n)
        {
            day += ((q[n - 1] - k) / k);
        }
        cout << day + 1 << endl;
    }
    return 0;
}