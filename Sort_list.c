#include <stdlib.h>

struct ListNode* split(struct ListNode* head, int step) {
    if (head == NULL) return NULL;
    
    for (int i = 1; i < step && head->next != NULL; i++) {
        head = head->next;
    }
    
    struct ListNode* rest = head->next;
    head->next = NULL;
    return rest;
}

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2, struct ListNode** nextTail) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (l1 != NULL) ? l1 : l2;
    
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    *nextTail = tail;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    int length = 0;
    struct ListNode* curr = head;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    
    struct ListNode dummy;
    dummy.next = head;
    
    for (int step = 1; step < length; step *= 2) {
        struct ListNode* prevTail = &dummy;
        curr = dummy.next;
        
        while (curr != NULL) {
            struct ListNode* left = curr;
            struct ListNode* right = split(left, step);
            curr = split(right, step);
            
            struct ListNode* nextGroupTail = NULL;
            prevTail->next = merge(left, right, &nextGroupTail);
            prevTail = nextGroupTail;
        }
    }
    
    return dummy.next;
}
