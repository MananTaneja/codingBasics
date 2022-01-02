#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, m;
        cin >> l >> r >> m;
        int n = 1;
        bool firstAns = false;
        while (!firstAns)
        {
            for (int a = l; a <= r && !firstAns; a++)
            {
                for (int b = l; b <= r && !firstAns; b++)
                {
                    for (int c = l; c <= r && !firstAns; c++)
                    {
                        int sol = n * a + b - c;
                        if (sol == m)
                        {
                            firstAns = true;
                            cout << a << " " << b << " " << c << endl;
                            break;
                        }
                    }
                }
            }
            n++;
        }
    }

    return 0;
}