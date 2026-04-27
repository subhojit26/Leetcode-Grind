/*
 * Problem  : 92. Reverse Linked List II
 * Difficulty: Medium
 * Topics   : Linked List
 * URL      : https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp1=dummy;
        ListNode* temp2=dummy;

        for(int i=1;i<left;i++){
            temp1=temp1->next;
        }

        for(int i=1;i<=right;i++){
            temp2=temp2->next;
        }

        ListNode* temp3=temp1->next;
        temp1->next=NULL;
        ListNode* temp4=temp2->next;
        temp2->next=NULL;

        ListNode* temp5=reverse(temp3);
        temp1->next=temp5;
        while(temp5->next!=NULL){
            cout<<temp5->val<<" ";
            temp5=temp5->next;
        }
        temp5->next=temp4;
        return dummy->next;
    }
};