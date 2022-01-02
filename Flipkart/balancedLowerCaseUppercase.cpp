#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(map<int, int> &mp)
{
    vector<vector<int>> merged;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {

        if (merged.empty() || merged.back()[1] < it->first)
        {
            merged.push_back({it->first, it->second});
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], it->second);
        }
    }

    return merged;
}

string balancedString(string s)
{
    const int n = s.length();
    vector<int> lower(26, INT_MIN);
    vector<int> upper(26, INT_MIN);
    int intervalSize = INT_MAX;
    int start = 0;
    bool answer = false;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (isupper(ch))
        {
            upper[ch - 'A'] = i;
        }
        else
        {
            lower[ch - 'a'] = i;
        }

        map<int, int> mp;

        for (int k = 0; k < 26; k++)
        {
            int minValue = min(lower[k], upper[k]);
            int maxValue = max(lower[k], upper[k]);
            mp[minValue] = max(mp[minValue], maxValue);
        }

        vector<vector<int>> merged = mergeIntervals(mp);
        // mp.clear();
        // cout << "At i: " << i << endl;
        for (int j = 0; j < merged.size(); j++)
        {
            // cout << merged[j][0] << " " << merged[j][1] << endl;

            if (merged[j][0] != INT_MIN)
            {
                int curInterval = merged[j][1] - merged[j][0] + 1;
                answer = true;
                if (curInterval < intervalSize)
                {

                    start = merged[j][0];
                    intervalSize = curInterval;
                }
            }
        }
    }

    return (answer) ? s.substr(start, intervalSize) : "no answer";
}

int main()
{
    string str = "AcZCbaBz";

    string res = balancedString(str);
    cout << res << endl;

    return 0;
}