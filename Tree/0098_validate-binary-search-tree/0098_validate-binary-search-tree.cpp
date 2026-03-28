/*
 * Problem  : 98. Validate Binary Search Tree
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Binary Search Tree, Binary Tree
 * URL      : https://leetcode.com/problems/validate-binary-search-tree/
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
    bool solver(TreeNode* root, long long int mini, long long int maxi){
        if(root==NULL){
				return true;
			}
			if(root->val>=maxi || root->val<=mini){
				return false;
			}
			return solver(root->left, mini, root->val)&& solver(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {

        return solver(root, LLONG_MIN,LLONG_MAX);
    }
};