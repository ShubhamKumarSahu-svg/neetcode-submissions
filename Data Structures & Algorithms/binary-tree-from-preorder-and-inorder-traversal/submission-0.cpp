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
    TreeNode* buildBST(vector<int>& preorder,vector<int>& inorder,unordered_map<int,int> inorderIndex,int &preIndex,int start,int end){
        if(start > end || preIndex > preorder.size()){
            return NULL;
        }
        int val = preorder[preIndex++];
        TreeNode* root = new TreeNode(val);
        root->left = buildBST(preorder,inorder,inorderIndex,preIndex,start,inorderIndex[val] - 1);
        root->right = buildBST(preorder,inorder,inorderIndex,preIndex,inorderIndex[val] + 1,end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderIndex;
        for(int i = 0; i < inorder.size() ;i++){
            inorderIndex[inorder[i]] = i; 
        }
        int start = 0;
        int end = inorder.size() - 1;
        int preIndex = 0;
        return buildBST(preorder,inorder,inorderIndex,preIndex,start,end);
    }
};
