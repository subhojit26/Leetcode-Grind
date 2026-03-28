/*
 * Problem  : 437. Path Sum III
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/path-sum-iii/
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
    int solver(TreeNode* root, long long int sum, int targetSum, unordered_map<long long int,int> &mp){
        if(root==NULL){
            return 0;
        }
        sum+=root->val;
        int count=0;
        if(sum==targetSum){
            count++;
        }
        if(mp.find(sum-targetSum)!=mp.end()){
            count+=mp[sum-targetSum];
        }
        mp[sum]++;
        count+=solver(root->left,sum,targetSum,mp);
        count+=solver(root->right,sum,targetSum,mp);
        mp[sum]--;
        return count;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long int sum=0;
        unordered_map<long long int,int> mp;
        return solver(root, sum, targetSum,mp);
        
    }
};