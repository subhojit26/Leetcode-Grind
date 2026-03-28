/*
 * Problem  : 1029. Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Topics   : Hash Table, Tree, Depth-First Search, Breadth-First Search, Sorting, Binary Tree
 * URL      : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int, int>>> q;
        map<int,map<int, multiset<int>>> mp;
        q.push({root,{0,0}});
        vector<vector<int>> ver;
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int depth=q.front().second.second;
            int level=q.front().second.first;
            q.pop();

            mp[level][depth].insert(curr->val);

            if(curr->left){
                q.push({curr->left,{level-1,depth+1}});
            }
            if(curr->right){
                q.push({curr->right,{level+1,depth+1}});
            }
        }

        for(auto it: mp){
            vector<int> temp;
            for(auto p:it.second)
            {
                temp.insert(temp.end(),p.second.begin(),p.second.end());
            }
            ver.push_back(temp);
        }
        return ver;
    }
};