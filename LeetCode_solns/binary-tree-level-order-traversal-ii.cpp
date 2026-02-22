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
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        level2(root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void level2(TreeNode* root){
        q.push(root);
        while(q.size() > 0){
            int size = q.size();
            vector<int> x;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                x.push_back(curr->val);
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            ans.push_back(x);
        }
    }
};
