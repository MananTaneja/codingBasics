#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "Attack cnsid sdcsivn sdjkjkcsdj";
    string sub = "";
    vector<string> temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (sub.length() == 6)
        {
            temp.push_back(sub);
            sub = "";
        }
        if (s[i] == ' ')
        {
            sub += '*';
        }
        else
        {
            sub += s[i];
        }
    }

    if (sub.length() != 0)
    {
        for (int i = sub.length(); i < 6; i++)
        {
            sub += '.';
        }
        temp.push_back(sub);
    }

    string res = "";

    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            res += temp[i][j];
        }
    }

    cout << res << endl;

    return 0;
}