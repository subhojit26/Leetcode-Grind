/*
 * Problem  : 129. Sum Root to Leaf Numbers
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    void solver(TreeNode* root, int &curr, int &total){
        if(root==NULL){
            return;
        }
        curr=curr*10+root->val;
        cout<<curr<<" ";
        if(root->left){
            solver(root->left,curr,total);
            curr=curr/10;
        }
        if(root->right){
            solver(root->right, curr, total);
            curr=curr/10;
        }
        if(root->left==NULL && root->right==NULL){
            total+=curr;
        }
    }
    int sumNumbers(TreeNode* root) {
        int curr=0;
        int total=0;
        solver(root,curr,total);
        return total;
    }
};