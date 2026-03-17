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
    double avg(const vector<int>& nums) {
        if (nums.empty()) return 0.0;
        long long sum = 0;
        for (int x : nums) sum += x;
        return (double)sum / nums.size();
    }
    vector<double> averageOfLevels(TreeNode* root) {
        levelorder(root);
        return ans;
    }
    queue<TreeNode*> q; 
    vector<double> ans;
    void levelorder(TreeNode* root){
        q.push(root);
        while(q.size()>0){
            int size=q.size();
            vector<int> x;
            for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();
            x.push_back(curr->val);
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
            }    
            ans.push_back(avg(x));
        }
    }
};