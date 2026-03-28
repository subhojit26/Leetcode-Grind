/*
 * Problem  : 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Topics   : Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
 * URL      : https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* solver(ListNode* l1, ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }else{
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        if(l1!=NULL){
            temp->next=l1;
        }
        if(l2!=NULL){
            temp->next=l2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int interval=1;
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        if(n==1){
            return lists[0];
        }
        while(interval<n){
            for(int i=0;i+interval<n;i+=interval*2){
                lists[i]=solver(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return lists[0];
    }
};