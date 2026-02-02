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
   int count=0;
    void levelorder(TreeNode* root){
        queue <TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>0){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(!q.empty()){ 
                    count++;
                    q.push(NULL);
                    continue;
                    }
                else break;
            }
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        levelorder(root);
        return count+1;
    }
};