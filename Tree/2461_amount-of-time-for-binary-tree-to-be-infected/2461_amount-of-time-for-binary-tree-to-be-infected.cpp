/*
 * Problem  : 2461. Amount of Time for Binary Tree to Be Infected
 * Difficulty: Medium
 * Topics   : Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
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
    int findTime(TreeNode* target, map<TreeNode*, TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int>vis;
        vis[target]=1;
        int time=0;

        while(!q.empty()){
            int s=q.size();
            int fl=0;

            while(s--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    fl=1;
                    q.push(curr->left);
                    vis[curr->left]=1;
                }
                if(curr->right && !vis[curr->right]){
                    fl=1;
                    q.push(curr->right);
                    vis[curr->right]=1;
                }
                if(mp[curr] && !vis[mp[curr]]){
                    fl=1;
                    q.push(mp[curr]);
                    vis[mp[curr]]=1;
                }
            }
            if(fl){
                time++;
            }
        }
        return time;
    }
    TreeNode* mapUsingBFS(map<TreeNode*, TreeNode*> &mp, TreeNode* root, int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* target;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                target=node;
            }
            if(node->left){
                q.push(node->left);
                mp[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right]=node;
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;
        TreeNode* target=mapUsingBFS(mp,root,start);
        int time=findTime(target,mp);
        return time;
    }
};