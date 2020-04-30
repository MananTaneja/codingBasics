#include<bits/stdc++.h>

using namespace std;


vector<int> psych(vector<int>& scores, vector<int>& lower, vector<int>& upper) {
    vector<int> ans;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < lower.size() && i < upper.size(); i++) {
        int l = lower[i];
        int u = upper[i];
        int j = 0;
        while(l > scores[j]) j++;
        int k = scores.size() - 1;
        while(u < scores[k]) k--;
        ans.push_back(k-j+1);
    }

    return ans;
}

int main() {

    int a, b, c;
    cin >> a;
    vector<int> scores;
    for(int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }
    cin >> b;
    vector<int> lower;
    for(int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        lower.push_back(temp);
    }
    cin >> c;
    vector<int> upper;
    for(int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        upper.push_back(temp);
    }
    
    vector<int> ans;
    ans = psych(scores, lower, upper);

    cout << "\n\n\n\n\n";

    for(int x: ans) {
        cout << x << " ";
    }

    cout << endl;
    
    return 0;
}