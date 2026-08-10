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
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool ltr=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> tmp(size);
            int first=0,last=size-1;
            while(size--){
                TreeNode* t=q.front();
                q.pop();
                if(ltr){
                    tmp[first]=t->val;
                    first++;
                }else{
                    tmp[last]=t->val;
                    last--;
                }
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            res.push_back(tmp);
            ltr=!ltr;
        }
        return res;
    }
};