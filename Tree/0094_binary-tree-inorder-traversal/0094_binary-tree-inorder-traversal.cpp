/*
 * Problem  : 94. Binary Tree Inorder Traversal
 * Difficulty: Easy
 * Topics   : Stack, Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/binary-tree-inorder-traversal/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                
                TreeNode* temp=curr->left;
                while(temp->right!=NULL && temp->right!=curr){
                    temp=temp->right;
                }
                TreeNode* IP=temp;
                if(IP->right==NULL){
                    IP->right=curr;
                    curr=curr->left;
                }else{
                    IP->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};