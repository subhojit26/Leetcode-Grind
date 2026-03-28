/*
 * Problem  : 662. Maximum Width of Binary Tree
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int mx=0;
        while(!q.empty()){
            unsigned long long start=q.front().second;
            unsigned long long end=q.back().second;
            mx=max(mx,(int)(end-start+1));
            int size=q.size();
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                if(node.first->left){
                    q.push({node.first->left,node.second*2+1});
                }
                if(node.first->right){
                    q.push({node.first->right,node.second*2+2});
                }
            }
        }
        return mx;
    }
};