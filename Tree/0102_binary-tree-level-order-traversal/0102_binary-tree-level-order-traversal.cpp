/*
 * Problem  : 102. Binary Tree Level Order Traversal
 * Difficulty: Medium
 * Topics   : Tree, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<pair<int, TreeNode*>> q;
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        q.push({0,root});

        while(!q.empty()){
            int level=q.front().first;
            TreeNode* node=q.front().second;

            q.pop();

            mp[level].push_back(node->val);
            if(node->left){
                q.push({level+1,node->left});
            }
            if(node->right){
                q.push({level+1,node->right});
            }
        }
        for(auto it:mp){
            vector<int> temp;
            for(auto pt:it.second){
                temp.push_back(pt);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};