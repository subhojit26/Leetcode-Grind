/*
 * Problem  : 1116. Maximum Level Sum of a Binary Tree
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int mx=INT_MIN;
        unordered_map<int, vector<int>> mp;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;

            int s=q.size();
            q.pop();
            mp[level].push_back(node->val);
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }

        int h=findHeight(root);
        int ans;
        for(int i=0;i<h;i++){
            vector<int> temp=mp[i];
            int sum=accumulate(temp.begin(),temp.end(),0);
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<" "<<sum;
            }
            cout<<"\n";
            if(sum>mx){
                mx=sum;
                ans=i;
            }
        }
        return ans+1;
    }
};