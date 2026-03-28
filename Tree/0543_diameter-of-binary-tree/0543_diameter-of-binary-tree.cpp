/*
 * Problem  : 543. Diameter of Binary Tree
 * Difficulty: Easy
 * Topics   : Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/diameter-of-binary-tree/
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
int mx=0;
    int solver(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight=solver(root->left);
        int rightHeight=solver(root->right);
        mx=max(leftHeight+rightHeight,mx);
        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solver(root);
        return mx;
    }
};