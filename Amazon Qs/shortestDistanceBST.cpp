#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *shortestDistanceBST(TreeNode *root, int node1, int node2)
{
}

int main()
{
    int n = 2;
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int node1 = 1, node2 = 6;
    cout << shortestDistanceBST(vec, node1, node2) << "\n";
    return 0;
}