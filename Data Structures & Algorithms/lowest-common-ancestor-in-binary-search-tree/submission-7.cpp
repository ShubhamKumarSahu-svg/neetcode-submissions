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
    TreeNode* lcaBST(TreeNode* root, int p, int q){
        if(root == NULL) return NULL;

        if(root->val >= p && root->val <= q) return root;
        else if(root->val < p) return lcaBST(root->right,p,q);
        else if(root->val > q) return lcaBST(root->left,p,q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return nullptr;
        }

        return lcaBST(root,min(p->val,q->val),max(p->val,q->val));
    }
};
