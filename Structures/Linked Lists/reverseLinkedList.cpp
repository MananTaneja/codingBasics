#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode() {this->val = 0; next = nullptr;}
    ListNode(int d) {this->val = d; next = nullptr;}
};



ListNode* reverseLinkedList(ListNode* root) {
    if(!root || root->next == nullptr) return NULL;

    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* cur = root;

    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;

    return root;
}

void printLinkedList(ListNode* root) {
    if(!root) return;

    while(root) {
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

    return;
}


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next
        = new ListNode(8);
    
    cout << "Before Reversing: " << endl;
    printLinkedList(head);

    cout << "After Reversing: " << endl;
    printLinkedList(reverseLinkedList(head));
    return 0;
}