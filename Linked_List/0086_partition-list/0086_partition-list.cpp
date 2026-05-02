/*
 * Problem  : 86. Partition List
 * Difficulty: Medium
 * Topics   : Linked List, Two Pointers
 * URL      : https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode(-1);
        ListNode* more=new ListNode(-1);
        ListNode* tl=less;
        ListNode* tm=more;
        ListNode* temp=head;
        if(head==NULL){
            return head;
        }

        while(temp!=NULL){
            ListNode* nextNode = temp->next;
            temp->next=NULL;
            if(temp->val<x){
                tl->next=temp;
                tl=tl->next;
            }else{
                tm->next=temp;
                tm=tm->next;
            }
            temp=nextNode;
        }
        tl->next=more->next;
        return less->next;
    }
};