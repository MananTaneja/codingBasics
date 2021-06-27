#include<bits/stdc++.h>
using namespace std;

vector<pair<char, int>> topKStocks(vector<pair<char, int>>& stream, int k) {
    vector<pair<int, char>> v;
    unordered_map<char, pair<int, vector<pair<int, char>>::iterator>> mp;

    make_heap(v.begin(), v.end());

    for(auto stock: stream) {
        if(mp.find(stock.first) == mp.end()) {
            v.push_back({stock.second, stock.first});
            vector<pair<int, char>>::iterator it = v.end()-1;
            push_heap(v.begin(), v.end());
            mp[stock.first] = {stock.second, it};
        }
        else {
            v.erase(mp[stock.first].second);
            cout << "Erasing " << stock.first << endl;
            make_heap(v.begin(), v.end());
            v.push_back({stock.second, stock.first});
            vector<pair<int, char>>::iterator it = v.end()-1;   
            push_heap(v.begin(), v.end());
            mp[stock.first] = {stock.second, it};
        }
        

        // if(v.size() > k+1) {
        //     v.pop_front();
        // }
    }

    vector<pair<char, int>> res;

    for(int i = 0; i < k && i < v.size(); i++) {
        res.push_back({v[i].second, v[i].first});
    }

    return res;
}






int main() {
    vector<pair<char, int>> stream = {{'a', 10}, {'b',20}, {'c',30}, {'d', 40}, {'a', 30}, {'d',10}};
    // priority_queue <int, vector<int>, greater<int> > pq; // min heap

    int k = 2;

    vector<pair<char, int>> res = topKStocks(stream, k);

    // for(auto stock: stream) {
    //     if(mp.find(stock.first) == mp.end()) {
    //         pq.push({stock.second, stock.first});
    //         mp[stock.first] = stock.second;
    //     }
    //     else {
    //         pq.push({stock.second, stock.first});
    //         mp[stock.first] = stock.second;
    //     }
    // }

    // // Printing
    // while(!pq.empty() && k) {
    //     if(mp[pq.top().second] == pq.top().first) {
    //         cout << pq.top().first << " " << pq.top().second << endl;
    //         k--;
    //     }
    //     pq.pop();
    // }

    for(auto v: res) {
        cout << v.first << ": " << v.second << endl;
    }

    return 0;
}