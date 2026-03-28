/*
 * Problem  : 104. Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int solver(TreeNode* root, int &mx){
        if(root==NULL){
            return 0;
        }

        int left=1+solver(root->left,mx);
        int right=1+solver(root->right,mx);
        mx=max(left,right);
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        int mx=0;
        solver(root,mx);
        return mx;
    }
};