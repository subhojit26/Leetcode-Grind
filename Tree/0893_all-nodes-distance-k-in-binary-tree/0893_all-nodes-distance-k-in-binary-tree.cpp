/*
 * Problem  : 893. All Nodes Distance K in Binary Tree
 * Difficulty: Medium
 * Topics   : Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findNodes(map<TreeNode*, TreeNode*> mp, TreeNode* target, int k){
        queue<TreeNode*> q;
        q.push(target);
        vector<int> ans;
        map<TreeNode*,int> vis;
        vis[target]=1;
        int level=-1;

        while(!q.empty()){
            int s=q.size();
            level++;

            while(s--){
                TreeNode* curr=q.front();
                q.pop();

                if(level==k){
                    ans.push_back(curr->val);
                }

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=1;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=1;
                }
                if(mp[curr] && !vis[mp[curr]]){
                    q.push(mp[curr]);
                    vis[mp[curr]]=1;
                }
            }
        }
        return ans;
    }
    void mapUsingBFS(map<TreeNode*, TreeNode*> &mp, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                mp[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        mapUsingBFS(mp,root);
        vector<int> ans=findNodes(mp,target,k);
        return ans;
    }
};