#include <bits/stdc++.h>
using namespace std;

int main()
{
    int useless;
    cin >> useless;
    string s;
    vector<int> prevVotes;
    vector<bool> isFilled;
    cin >> s;
    for (char c : s)
    {
        int vote;
        bool fill;
        if (c == 'A')
        {
            vote = 1;
            fill = true;
        }
        else if (c == 'B')
        {
            vote = -1;
            fill = true;
        }
        else
        {
            vote = 0;
            fill = false;
        }
        prevVotes.push_back(vote);
        isFilled.push_back(fill);
    }

    // for (int vote : prevVotes)
    // {
    //     if (vote > 0)
    //         cout << "A ";
    //     else if (vote < 0)
    //         cout << "B ";
    //     else
    //         cout << "- ";
    // }
    // cout << endl;

    int reps = 0;
    bool isSame = false;
    const int last = prevVotes.size() - 1;
    vector<int> curVotes;
    while (reps <= last && !isSame)
    {
        curVotes = prevVotes;

        if (curVotes[1] != 0)
        {
            curVotes[0] = (curVotes[1] > 0) ? curVotes[1] + 1 : curVotes[1] - 1;
        }

        if (curVotes[last - 1] != 0)
        {
            curVotes[last] = (curVotes[last - 1] > 0) ? curVotes[last - 1] + 1 : curVotes[last - 1] - 1;
        }

        for (int i = 1; i < last; i++)
        {
            if (isFilled[i])
                continue;
            int cur = (curVotes[i] == 0) ? INT_MAX : abs(curVotes[i]);
            int left = (curVotes[i - 1] < 0) ? abs(curVotes[i - 1]) : INT_MAX;
            int right = (curVotes[i + 1] > 0) ? abs(curVotes[i + 1]) : INT_MAX;

            if (left == right)
                continue;
            else if (cur > left && right > left)
            {
                curVotes[i] = curVotes[i - 1] - 1;
            }
            else if (cur > right && left > right)
            {
                curVotes[i] = curVotes[i + 1] + 1;
            }
        }

        reps++;

        if (prevVotes == curVotes)
            isSame = true;

        prevVotes = curVotes;
    }

    int countA = 0;
    int countB = 0;

    for (int vote : curVotes)
    {
        if (vote > 0)
            countA++;
        else if (vote < 0)
            countB++;
    }

    if (countA == countB)
    {
        cout << "Coalition Government";
    }
    else
    {
        if (countA > countB)
        {
            cout << "A";
        }
        else
        {
            cout << "B";
        }
    }

    return 0;
}