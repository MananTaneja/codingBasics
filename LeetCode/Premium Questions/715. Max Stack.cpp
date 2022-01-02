#include <bits/stdc++.h>
using namespace std;

class MaxStack
{
public:
    stack<int> s1;
    int maxElement;
    stack<int> temp;
    MaxStack()
    {
        maxElement = INT_MIN;
    }
    void push(int x)
    {
        s1.push(x);
        if (x > maxElement)
        {
            maxElement = x;
        }
    }

    void pop()
    {
        int val = s1.top();
        if (val == maxElement)
        {
        }
        s1.pop();
    }

    int top()
    {
        return s1.top();
    }

    int peekMax() // O(N)
    {
        return maxElement;
    }

    int popMax() // O(N)
    {
        int val = peekMax();
        if (val == INT_MIN)
        {
        }
    }
};

int main()
{

    return 0;
}
