/*
 * Problem  : 61. Rotate List
 * Difficulty: Medium
 * Topics   : Linked List, Two Pointers
 * URL      : https://leetcode.com/problems/rotate-list/
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
    int findLength(ListNode* temp){
        int l=0;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int len=findLength(temp);
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        k=k%len;
        if(k==0){
            return head;
        }
        
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }

        int d=len-k;
        for(int i=1;i<d;i++){
            temp=temp->next;
        }
        ListNode* newHead=temp->next;
        temp->next=NULL;
        tail->next=head;
        return newHead;
    }
};