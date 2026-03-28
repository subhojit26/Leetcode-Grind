/*
 * Problem  : 572. Subtree of Another Tree
 * Difficulty: Easy
 * Topics   : Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
 * URL      : https://leetcode.com/problems/subtree-of-another-tree/
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
    bool helper(TreeNode* subroot, TreeNode* root){
        if(subroot==NULL || root==NULL){
            return subroot==root;
        }
        return helper(subroot->left,root->left)&&helper(subroot->right,root->right)&&(subroot->val==root->val);
    }
    bool solver(TreeNode* root, TreeNode* subroot){
        if(root==NULL && subroot==NULL){
            return true;
        }
        if(root==NULL || subroot==NULL){
            return false;
        }
        if(subroot->val==root->val){
            bool res =helper(subroot,root);
            if(res){
                return true;
            }
        }
        return solver(root->left,subroot)||solver(root->right,subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solver(root,subRoot);
    }
};