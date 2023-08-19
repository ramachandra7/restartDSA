/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)return {};
    queue<pair<TreeNode<int>*,int>>q;
    
    map<int,int>mp;
    q.push({root,0});
    mp[0]=root->data;
    while(q.size()!=0){
        int size=q.size();
        while(size--)
        {
            auto it=q.front();
            q.pop();
            auto node=it.first;
            int col=it.second;
            if(mp.find(col)==mp.end())mp[col]=node->data;
            
            if(node->left){
                q.push({node->left,col-1});
            }
            if(node->right){
                q.push({node->right,col+1});
            }
            
        }
        
    }
    vector<int>ans;
    for(auto it:mp)
    ans.push_back(it.second);
    return ans;
    
    
}
