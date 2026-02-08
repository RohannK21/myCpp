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
    unordered_map <int,int> m;
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int& prei,int left,int right){
        if(left>right) return NULL;
        TreeNode* root= new TreeNode(preorder[prei++]);
        int inidx=m[root->val];
        root->left=helper(preorder,inorder,prei,left,inidx-1);
        root->right=helper(preorder,inorder,prei,inidx+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
        m[inorder[i]]=i;
        }
        int prei=0;
        return helper(preorder,inorder,prei,0,inorder.size()-1);
    }
};