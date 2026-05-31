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
    pair<bool,int> isBalance(TreeNode* root){
        if(root == NULL) return {true,0};

        pair<bool,int> left = isBalance(root->left);
        pair<bool,int> right = isBalance(root->right);

        pair<bool,int> ans;
        ans.first = left.first && right.first && (abs(left.second - right.second) < 2);
        ans.second = max(left.second ,right.second) + 1;

        return ans; 
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalance(root).first;
    }
};
