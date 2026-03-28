/*
 * Problem  : 237. Delete Node in a Linked List
 * Difficulty: Medium
 * Topics   : Linked List
 * URL      : https://leetcode.com/problems/delete-node-in-a-linked-list/
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
    void deleteNode(ListNode* node) {
        ListNode* curr=node;
        while(curr->next->next!=NULL){
            curr->val=curr->next->val;
            curr=curr->next;
        }
        curr->val=curr->next->val;
        curr->next=NULL;
    }
};