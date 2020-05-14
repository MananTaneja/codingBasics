#include<bits/stdc++.h>

using namespace std;


// Basoc structure of TrieNode 
struct TrieNode {
    TrieNode *children[26];
    bool endOfWord = false;
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

// Makes a new TrieNode with default values and returns it

// TrieNode* getNode() {
//     TrieNode *newNode = new TrieNode;

//     newNode->endOfWord = false;

//     for(int i = 0; i < 26; i++) {
//         newNode->children[i] = NULL;
//     }

//     return newNode;
// }


// Inserting into TrieNode

void insert(TrieNode* root, string word) {
    
    //  Kinda like attaching current to head
    TrieNode *nodeCrawler = root;

    for(int i = 0; i < word.length(); i++) {
        int ind = word[i] - 'a';

        // Makes and assigns an empty TrieNode if it doesn't already exist
        if(nodeCrawler->children[ind] == NULL) {
            nodeCrawler->children[ind] = new TrieNode();
        }

        nodeCrawler = nodeCrawler->children[ind];
    }

    nodeCrawler->endOfWord = true;

}


// Search Function - need to check if this returns prefix based search or entire word search

bool search (TrieNode* root , string word) {
    
    TrieNode* nodeCrawler = root;
    
    for(int i = 0; i < word.length(); i++) {
        int ind = word[i] - 'a';
        if(nodeCrawler->children[ind] == NULL) {
            return false;
        }
        nodeCrawler = nodeCrawler->children[ind];
    }

    return (nodeCrawler != NULL && nodeCrawler->endOfWord == true); // I think if we just remove the condition of nodeCrawler->endOfWord == true we can do prefix based searching
}

int main() {
    vector<string> words = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    
    TrieNode* root = new TrieNode();

    for(int i = 0; i < words.size(); i++) {
        insert(root, words[i]);
    }

    search(root, "the")?cout<<"the exists":cout<<"the doesnt exist";
    cout << endl;
    search(root, "these")? cout<< "these exists": cout << "these doesnt exist";
    cout << endl;
    return 0;
}