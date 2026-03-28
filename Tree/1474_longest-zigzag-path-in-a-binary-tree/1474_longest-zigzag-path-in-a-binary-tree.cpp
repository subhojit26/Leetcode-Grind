/*
 * Problem  : 1474. Longest ZigZag Path in a Binary Tree
 * Difficulty: Medium
 * Topics   : Dynamic Programming, Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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
    void solver(TreeNode* root, string state,int count){
        if(root==NULL){
            return;
        }
        mx=max(count,mx);
        if(state=="left"){
            solver(root->left,"left",1);
            solver(root->right,"right",count+1);
        }
        if(state=="right"){
            solver(root->left,"left",count+1);
            solver(root->right,"right",1);
        }
    }
    int longestZigZag(TreeNode* root) {
        int count=1;
        solver(root->left,"left",count);
        solver(root->right,"right",count);
        return mx;
    }
};