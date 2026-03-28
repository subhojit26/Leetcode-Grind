/*
 * Problem  : 234. Palindrome Linked List
 * Difficulty: Easy
 * Topics   : Linked List, Two Pointers, Stack, Recursion
 * URL      : https://leetcode.com/problems/palindrome-linked-list/
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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int len=findLength(head);
        ListNode* mid=findMiddle(head);
        ListNode* nhead=mid->next;
        mid->next=NULL;
        ListNode* head2=reverse(nhead);
        
        
        if(len%2==0){
            while(head!=NULL && head2!=NULL){
                if(head->val!=head2->val){
                    return false;
                }
                head=head->next;
                head2=head2->next;
            }
            return true;
        }else{
            while(head!=mid && head2!=NULL){
            
                if(head->val!=head2->val){
                    return false;
                }
                head=head->next;
                head2=head2->next;
            }
            return true;
        }
    }
};