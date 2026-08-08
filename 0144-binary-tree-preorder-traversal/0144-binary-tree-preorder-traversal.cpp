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
void fun(TreeNode* node,vector<int>& res){
    if(!node){
        return;
    }
    res.push_back(node->val);
    fun(node->left,res);
    fun(node->right,res);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        fun(root,res);
        return res;
    }
};