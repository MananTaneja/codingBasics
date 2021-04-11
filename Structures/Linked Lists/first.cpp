// Contains basic Singly Linked lists functions 
// 1. Printing
// 2. Calculating length




#include<bits/stdc++.h>

struct ListNode {
    int data;
    struct ListNode *next;
};


void print(struct ListNode *head) {
    struct ListNode *cur = head;
    for(cur = head; cur != NULL; cur = cur->next) {
        printf("%d", cur->data);
    }
    printf("\n");
}

int length(struct ListNode *head) {
    struct ListNode *cur  = head;
    int count = 0;
    for(cur = head; cur != NULL; cur = cur->next) {
        count++;
    }
    return count;
}

