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
private:
    void cntGood(TreeNode* root,int minVal,int &cnt){
        if(!root) return;

        if(root->val >= minVal){
            cnt++;
            minVal = max(root->val,minVal);
        } 
        cntGood(root->left,minVal,cnt);
        cntGood(root->right,minVal,cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        int minVal = INT_MIN;
        cntGood(root,minVal,cnt);
        return cnt;
    }
};
