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
    bool isSame(TreeNode* p,TreeNode* q){
        if((!p && q)|| (p && !q)) return false;

        if(!p && !q) return true;

        bool left = isSame(p->left,q->left);
        bool right = isSame(p->right,q->right);
        bool curr = left && right && (p->val == q->val);

        return curr;
    }

    void searchNode(TreeNode* root,int key,vector<TreeNode*> &temp){
        if(root == NULL){
            return;
        }
        if(root->val == key){
            temp.push_back(root);
        }
        searchNode(root->left,key,temp);
        searchNode(root->right,key,temp);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> temps;

        searchNode(root,subRoot->val,temps);
        
        for(auto temp : temps){
            if(isSame(temp,subRoot)) return true;
        }

        return false;
    }
};
