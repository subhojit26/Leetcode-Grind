/*
 * Problem  : 124. Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Topics   : Dynamic Programming, Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int solver(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }

        int lsum=max(0,solver(root->left,maxi));
        int rsum=max(0,solver(root->right,maxi));
        maxi=max(maxi,root->val+lsum+rsum);
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solver(root, maxi);
        return maxi;
    }
};