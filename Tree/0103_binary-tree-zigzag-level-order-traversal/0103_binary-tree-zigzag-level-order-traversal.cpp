/*
 * Problem  : 103. Binary Tree Zigzag Level Order Traversal
 * Difficulty: Medium
 * Topics   : Tree, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    void solver(TreeNode* root, vector<vector<int>> &ans){
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL){
            return;
        }
        int l=0;
        while(!q.empty()){
            int s=q.size();
            vector<int> level;

            while(s--){
                TreeNode* curr=q.front();
                q.pop();

                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(l%2==0){
                ans.push_back(level);
            }else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            l++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solver(root, ans);
        return ans;
    }
};