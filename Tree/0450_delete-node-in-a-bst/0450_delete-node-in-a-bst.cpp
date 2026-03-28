/*
 * Problem  : 450. Delete Node in a BST
 * Difficulty: Medium
 * Topics   : Tree, Binary Search Tree, Binary Tree
 * URL      : https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* findSuccessor(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }

        else{
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            if(root->left==NULL){
                return root->right;
            }
            if(root->right==NULL){
                return root->left;
            }

            TreeNode* successor=findSuccessor(root->right);
            root->val=successor->val;
            root->right=deleteNode(root->right,successor->val);
        }
        return root;
    }
};