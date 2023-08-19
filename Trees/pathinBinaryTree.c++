/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool path(TreeNode* A, vector<int> &ans, int B){
    if(A==NULL)return false;
    ans.push_back(A->val);
    if(A->val==B)return true;
    if(path(A->left,ans,B) || path(A->right,ans,B)) return true;
    ans.pop_back();
    return false;
}
 
 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    if(A->val==B)return {B};
    vector<int>ans;
    path(A,ans,B);
    return ans;
    
}
