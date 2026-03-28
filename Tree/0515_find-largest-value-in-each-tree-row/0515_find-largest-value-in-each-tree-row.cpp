/*
 * Problem  : 515. Find Largest Value in Each Tree Row
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(root==NULL){
            return ans;
        }

        while(!q.empty()){
            int s=q.size();
            int mx=INT_MIN;
            while(s--){
                TreeNode* curr=q.front();
                q.pop();

                mx=max(mx,curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};