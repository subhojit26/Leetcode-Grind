/*
 * Problem  : 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Divide and Conquer, Tree, Binary Tree
 * URL      : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    int search(vector<int> inorder, int ele,int left, int right){
        for(int i=left;i<=right;i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solver(vector<int> &preorder, vector<int> &inorder,int &preInd, int left,int right){
        if(left>right){
            return NULL;
        }

        TreeNode* node=new TreeNode(preorder[preInd]);
        int ind=search(inorder,preorder[preInd],left,right);
        preInd++;
        node->left=solver(preorder,inorder,preInd,left,ind-1);
        node->right=solver(preorder,inorder,preInd,ind+1,right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preInd=0;
        return solver(preorder, inorder,preInd,0,inorder.size()-1);
    }
};