/*
 * Problem  : 148. Sort List
 * Difficulty: Medium
 * Topics   : Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
 * URL      : https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=NULL;

        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        temp->next=NULL;
        ListNode* l=sortList(head);
        ListNode* r=sortList(slow);

        return merge(l,r);
    }

    ListNode* merge(ListNode* l, ListNode* r){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(l!=NULL && r!=NULL){
            if(l->val<r->val){
                temp->next=l;
                l=l->next;
                temp=temp->next;
            }else{
                temp->next=r;
                r=r->next;
                temp=temp->next;
            }
        }
        if(l!=NULL){
            temp->next=l;
        }
        if(r!=NULL){
            temp->next=r;
        }

        return dummy->next;
    }
};