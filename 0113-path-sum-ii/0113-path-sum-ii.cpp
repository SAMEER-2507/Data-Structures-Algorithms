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
vector<vector<int>> res;
void fun(TreeNode* root,int sum,vector<int> tmp,int target){
    if(!root){
        return;
    }
    sum+=root->val;
    tmp.push_back(root->val);
    if(!root->left&&!root->right){
        if(sum==target){
            res.push_back(tmp);
        }
        tmp.pop_back();
        return;
    }
    fun(root->left,sum,tmp,target);
    fun(root->right,sum,tmp,target);
    tmp.pop_back();
    return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        fun(root,0,tmp,targetSum);
        return res;
    }
};