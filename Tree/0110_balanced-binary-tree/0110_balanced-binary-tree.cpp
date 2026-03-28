/*
 * Problem  : 110. Balanced Binary Tree
 * Difficulty: Easy
 * Topics   : Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/balanced-binary-tree/
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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left), height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int lh=height(root->left);
        int rh=height(root->right);

        if(abs(lh-rh)>1){
            return false;
        }

        if(isBalanced(root->left)==false || isBalanced(root->right)==false){
            return false;
        }
        return true;


    }
};