/*
 * Problem  : 337. House Robber III
 * Difficulty: Medium
 * Topics   : Dynamic Programming, Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/house-robber-iii/
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
    int solve(TreeNode* root, unordered_map<TreeNode*,int> &mp){
        if(root==NULL){
            return 0;
        }
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        int val=0;
        if(root->left!=NULL){
            val+=solve(root->left->right,mp)+solve(root->left->left,mp);
        }
        if(root->right!=NULL){
            val+=solve(root->right->right,mp)+solve(root->right->left,mp);
        }
        return mp[root]= max(val+root->val, solve(root->left,mp)+solve(root->right,mp));
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        return solve(root,mp);
    }
};