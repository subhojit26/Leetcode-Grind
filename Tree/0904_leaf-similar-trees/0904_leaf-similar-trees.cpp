/*
 * Problem  : 904. Leaf-Similar Trees
 * Difficulty: Easy
 * Topics   : Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/leaf-similar-trees/
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
    void findLeaf(TreeNode* root, vector<int> &leaf){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->val);
            return;
        }
        findLeaf(root->left,leaf);
        findLeaf(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        findLeaf(root1,leaf1);
        findLeaf(root2,leaf2);
        return (leaf1==leaf2);
    }
};