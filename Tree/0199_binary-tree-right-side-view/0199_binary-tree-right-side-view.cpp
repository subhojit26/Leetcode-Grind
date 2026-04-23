/*
 * Problem  : 199. Binary Tree Right Side View
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<pair<int, TreeNode*>> q;
        map<int, TreeNode*> mp;
        q.push({0,root});
        mp[0]=root;
        while(!q.empty()){
            int level=q.front().first;
            TreeNode* node=q.front().second;
            q.pop();

            mp[level]=node;
            if(node->left){
                q.push({level+1,node->left});
            }
            if(node->right){
                q.push({level+1,node->right});
            }
        }
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second->val);
        }
        return ans;
    }
};