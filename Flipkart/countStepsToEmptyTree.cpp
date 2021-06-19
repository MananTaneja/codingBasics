// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a
// Binary Tree Node
struct TreeNode {
	int val;
	TreeNode *left, *right;
};

// Function to allocate
// a new tree node
TreeNode* newNode(int val)
{
	TreeNode* node = new Node;
	node->val = val;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// Function to find the maximum height
// from leaf in the subtree rooted at
// current node and add that to hashmap
int maxHeightToLeafUTIL(
	TreeNode* curr, map<int, vector<int> >& mp)
{
	if (curr == NULL) {
		return 0;
	}

	// Max height to leaf in left subtree
	int leftLeaf
		= maxHeightToLeafUTIL(curr->left, mp);

	// Max height to leaf in right subtree
	int rightLeaf
		= maxHeightToLeafUTIL(curr->right, mp);

	// Max height to leaf in current subtree
	int maxHeightSubtree
		= 1 + max(leftLeaf, rightLeaf);

	// Adding current node to the Map
	mp[maxHeightSubtree].push_back(
		curr->val);

	return maxHeightSubtree;
}

// Function to find the count of leaf nodes
// by repeatedly removing the leaf nodes


// Driver code
int main()
{
	// Given Binary Tree
	TreeNode* root = newNode(2);
	root->right = newNode(7);
	root->right->right = newNode(6);
	root->left = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(8);
	root->left->right->left = newNode(3);
	root->left->right->right = newNode(4);
	// Function Call
	printAndDelete(root);

	return 0;
}
