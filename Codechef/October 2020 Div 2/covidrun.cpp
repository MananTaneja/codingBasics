#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        unordered_set<int> infected;
        int current = x;
        bool found = false;
        if (current == y)
        {
            found = true;
            cout << "YES" << endl;
            continue;
        }
        while (infected.find(current) == infected.end())
        {
            infected.insert(current);
            current = (current + k) % n;
            if (current == y)
            {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}