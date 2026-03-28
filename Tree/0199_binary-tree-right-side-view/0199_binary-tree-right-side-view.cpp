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
    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=1+findHeight(root->left);
        int right=1+findHeight(root->right);

        return max(left,right);

    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<pair<TreeNode*,int>> q;
        unordered_map<int,TreeNode*> mp;

        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;

            int s=q.size();
            q.pop();
            mp[level]=node;
    
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
            
        }
        int mx=INT_MIN;
        int h=findHeight(root);

        vector<int> ans;
        for(int i=0;i<h;i++){
            ans.push_back(mp[i]->val);
        }
        return ans;
    }
};