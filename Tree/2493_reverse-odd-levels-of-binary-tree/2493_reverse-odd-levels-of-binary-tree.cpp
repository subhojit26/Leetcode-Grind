/*
 * Problem  : 2493. Reverse Odd Levels of Binary Tree
 * Difficulty: Medium
 * Topics   : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * URL      : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel=0;
        while(!q.empty()){
            int s=q.size();
            vector<TreeNode*> node;

            while(s--){
                TreeNode* curr=q.front();
                q.pop();

                node.push_back(curr);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

            if(currentLevel%2==1){
                int left=0;
                int right=node.size()-1;
                while(left<=right){
                    swap(node[left]->val,node[right]->val);
                    left++;
                    right--;
                }
            }
            currentLevel++;
        }
        return root;
    }
};