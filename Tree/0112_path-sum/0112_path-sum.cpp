/*
 * Problem  : 112. Path Sum
 * Difficulty: Easy
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/path-sum/
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
    bool solver(int sum, TreeNode* root, int targetSum){
        if(root==NULL){
            return false;
        }
        if(sum+root->val==targetSum){
            if(root->left==NULL && root->right==NULL){
                return true;
            }
        }

        return solver(sum+root->val, root->left, targetSum)||solver(sum+root->val, root->right,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solver(0, root, targetSum);
    }
};