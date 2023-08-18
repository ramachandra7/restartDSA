TC: O(N)
SC: O(N)
Instead of vector use multiset



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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};
         vector<vector<int>>ans;
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,int>>q;

        int row=0;
        // int col=0;
        q.push({root,0});

        while(q.size()){
            int size=q.size();
            while(size--)
            {
                auto it=q.front();
                q.pop();
                auto present=it.first;
                auto col=it.second;
                mp[col][row].push_back(present->val);
                if(present->left)q.push({present->left,col-1});
                if(present->right)q.push({present->right,col+1});
            }
                row++;
        }

        for(auto it:mp){
            vector<int>column;
            for(auto it2:it.second)
            {
                int rowNow=it2.first;
                auto rowVector=it2.second;
                sort(rowVector.begin(),rowVector.end());
                column.insert(column.end(),rowVector.begin(),rowVector.end());
            }
            ans.push_back(column);
        }
return ans;
    }
};
