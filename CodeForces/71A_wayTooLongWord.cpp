#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.length() > 10) {
            string res = "";
            res += s[0];
            int count = 0;
            int i;
            for(i = 1; i < s.length() - 1; i++) {
                count++;
            }
            res += to_string(count);
            res += s[i];
            cout << res << endl;
        }
        else {
            cout << s << endl;
        }
    }
    return 0;
}