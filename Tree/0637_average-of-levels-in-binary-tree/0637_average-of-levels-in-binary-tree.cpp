/*
 * Problem  : 637. Average of Levels in Binary Tree
 * Difficulty: Easy
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<pair<int, TreeNode*>> q;
        map<int,vector<int>> mp;
        vector<double> ans;
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
            int sum=accumulate(temp.begin(),temp.end(),0);
            double average=(double)sum/temp.size();
            ans.push_back(average);
        }
        return ans;
    }
};