/*
 * Problem  : 2236. Maximum Twin Sum of a Linked List
 * Difficulty: Medium
 * Topics   : Linked List, Two Pointers, Stack
 * URL      : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        
        ListNode* mid=findMid(head);
        ListNode* temp=mid->next;
        mid->next=NULL;
        temp=reverse(temp);
        int mx=INT_MIN;
        while(head!=NULL && temp!=NULL){
            mx=max(head->val+temp->val,mx);
            head=head->next;
            temp=temp->next;
        }
        return mx;
    }
};