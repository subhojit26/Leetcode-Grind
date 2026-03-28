/*
 * Problem  : 1544. Count Good Nodes in Binary Tree
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    void solver(TreeNode* root,int mx,int &count){
        if(root==NULL){
            return;
        }
        if(root->val>=mx){
            mx=root->val;
            count++;
        }
        solver(root->left,mx,count);
        solver(root->right,mx,count);

    }
    int goodNodes(TreeNode* root) {
        int mx=root->val;
        int count=0;
        solver(root,mx,count);
        return count;
    }
};