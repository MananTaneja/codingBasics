#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<char>& s, char ele) {
    if(s.empty()) {
        s.push(ele);
        return;
    }

    char top = s.top();
    s.pop();
    insertAtBottom(s, ele);
    s.push(top);
}

void reverseStack(stack<char>& s) {
    if(s.empty()) return;

    char ele = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, ele);
}

int main() {
    stack<char> s;
    s.push('1');
    s.push('2');
    s.push('3');
    s.push('4');
    s.push('5');

    reverseStack(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}
