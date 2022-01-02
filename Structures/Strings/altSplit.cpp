#include<bits/stdc++.h>

using namespace std;

int main() {
    string str = "Hello,there,this,is,a,sample,string";
    string token = ",";
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }

    for(string s: result) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}