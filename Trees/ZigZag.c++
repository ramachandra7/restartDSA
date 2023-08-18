Approach : BFS queue
TC: O(N) - no of nodes visited
SC: O(N) - queue - height of binary tree - 



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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //bfs queue
        queue<TreeNode*>q;
        vector<vector<int>>zigzag;
        bool even=true;
        if(root==NULL)return {};
        if(root->left==NULL && root->right==NULL)return {{root->val}};
        q.push(root);
        while(q.size()!=0){
        int size=q.size();
        vector<int>level;
            while(size--){
                TreeNode* n=q.front();
                q.pop();
                level.push_back(n->val);
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }

            if(even==true)
            {
                even=false;
                zigzag.push_back(level);
            }else{
                even=true;
                reverse(level.begin(),level.end());
                zigzag.push_back(level);
            }

        }
        return zigzag;
    }
};
