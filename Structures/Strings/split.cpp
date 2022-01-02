#include<bits/stdc++.h>

using namespace std;

int main() {
    string data = "Hello,there,this,is,a,sample,string";
    char *help = strdup(data.c_str());
    char *token = strtok(help, ",");
    vector<string> split;
    while(token != NULL) {
        split.push_back(token);
        token = strtok(NULL, ",");
    }

    for(string s: split) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}