/*
 * Problem  : 19. Remove Nth Node From End of List
 * Difficulty: Medium
 * Topics   : Linked List, Two Pointers
 * URL      : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=findLength(head);
        if(len==1){
            return NULL;
        }
        if(len==n){
            return head->next;
        }
        int shift=len-n-1;
        ListNode* temp=head;
        while(shift>0){
            temp=temp->next;
            shift--;
        }
        temp->next=temp->next->next;
        return head;
    }
};