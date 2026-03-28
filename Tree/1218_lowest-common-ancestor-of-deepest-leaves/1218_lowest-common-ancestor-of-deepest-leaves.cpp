/*
 * Problem  : 1218. Lowest Common Ancestor of Deepest Leaves
 * Difficulty: Medium
 * Topics   : Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
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
    vector<vector<TreeNode*>> level(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<TreeNode*>> ans;

        while(!q.empty()){
            int s=q.size();
            vector<TreeNode*>temp;

            while(s--){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    TreeNode* findLCS(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left=findLCS(root->left, p, q);
        TreeNode* right=findLCS(root->right,p,q);

        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<TreeNode*>> levelOrder=level(root);
        int n=levelOrder.size();
        if(levelOrder[n-1].size()==1){
            return levelOrder[n-1][0];
        }
        else{
            TreeNode* lcs=findLCS(root, levelOrder[n-1][0],levelOrder[n-1][1]);
            if(levelOrder[n-1].size()==2){
                return lcs;
            }
            else{
                int s=levelOrder[n-1].size();
                for(int i=2;i<s;i++){
                    lcs=findLCS(root, lcs, levelOrder[n-1][i]);
                }
                return lcs;
            }
        }
    }
};