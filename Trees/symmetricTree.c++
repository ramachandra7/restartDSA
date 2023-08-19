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
    bool areSymmetric(TreeNode* l,TreeNode* r){
        if(l==NULL && r==NULL)return true;
        if(!l || !r || l->val!=r->val)return false;
        return (areSymmetric(l->left,r->right) && areSymmetric(l->right,r->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(!root || (root->left==NULL && root->right==NULL)) return true;
        return areSymmetric(root->left,root->right);
    }
};
