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
unordered_map<int,int> in;
int idx;
TreeNode* fun(vector<int>& postorder,int low,int high){
    if(low>high){
        return NULL;
    }
    TreeNode* node=new TreeNode(postorder[idx]);
    idx--;
    int id=in[node->val];
    node->right=fun(postorder,id+1,high);
    node->left=fun(postorder,low,id-1);
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx=inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }
        return fun(postorder,0,inorder.size()-1);
    }
};