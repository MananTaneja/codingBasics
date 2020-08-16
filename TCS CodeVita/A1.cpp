
#include <iostream>
using namespace std;

int main()
{
    int f;
    cin >> f;
    string s;
    cin >> s;
    int i = 0;
    int countA = 0;
    int countB = 0;
    int j = 0;
    while (j < f)
    {
        if (s[j] == 'A')
            countA++;
        else if (s[j] == 'B')
            countB++;
        j++;
    }
    while (s[i] == '-')
    {
        i++;
    }
    if (s[i] == 'A')
    {
        countA += i;
    }
    int start = i;
    for (; i < f;)
    {
        while (s[i] == '-' && i < f)
        {
            i++;
        }
        if (i == f)
        {
            break;
        }
        if (s[i] == 'A')
        {
            if (start == i)
            {
                i++;
                continue;
            }
            countA = countA + (i - start - 1);
            start = i;
            i++;
            continue;
        }
        start = i;
        i++;
        while (s[i] == '-' && i < f)
        {
            i++;
        }
        if (i == f)
            countB = countB + (i - start - 1);
        else
        {
            if (s[i] == 'A')
            {
                countA = countA + (i - start - 1) / 2;
                countB = countB + (i - start - 1) / 2;
                start = i;
                i++;
            }
            else
            {
                countB = countB + (i - start - 1);
            }
        }
    }
    if (countA == countB)
    {
        cout << "Coalition government";
    }
    else if (countA > countB)
    {
        cout << "A";
        ;
    }
    else
    {
        cout << "B";
    }
}
