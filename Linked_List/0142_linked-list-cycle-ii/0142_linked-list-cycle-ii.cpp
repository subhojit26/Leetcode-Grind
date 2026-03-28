/*
 * Problem  : 142. Linked List Cycle II
 * Difficulty: Medium
 * Topics   : Hash Table, Linked List, Two Pointers
 * URL      : https://leetcode.com/problems/linked-list-cycle-ii/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int f=0;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                f=1;
                break;
            }
        }
        if(f==1){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }else{
            return NULL;
        }
    }
};