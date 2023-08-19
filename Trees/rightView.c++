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
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
         if(!root)return {};
         queue<TreeNode*>q;
         q.push(root);
         while(q.size()){
             int size=q.size();
             TreeNode* it=NULL;
             while(size--)
             {
                it=q.front();
                 q.pop();
                 if(it->left)q.push(it->left);
                 if(it->right)q.push(it->right);

             }
             ans.push_back(it->val);

         }
         return ans;
    }
};
