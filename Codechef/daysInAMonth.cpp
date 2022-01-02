#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp = {{"mon", 0}, {"tues", 1}, {"wed", 2}, {"thurs", 3}, {"fri", 4}, {"sat", 5}, {"sun", 6}};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> week(7, 0);
        int num;
        string strDay;
        cin >> num >> strDay;
        int day = mp[strDay];
        for (int i = 0; i < num; i++)
        {
            week[day]++;
            day = (day + 1) % 7;
        }

        for (int count : week)
        {
            cout << count << " ";
        }

        cout << endl;
    }
    return 0;
}