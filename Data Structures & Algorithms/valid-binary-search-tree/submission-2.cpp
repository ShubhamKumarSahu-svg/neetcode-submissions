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
    bool isBST(TreeNode* root,int &minVal,int &maxVal){
        if(!root) return true;

        if(!(root->val > minVal && root->val < maxVal)) return false;

        return isBST(root->left,minVal,root->val) && isBST(root->right,root->val,maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        int minVal = INT_MIN;
        int maxVal = INT_MAX;

        return isBST(root,minVal,maxVal);
    }
};
