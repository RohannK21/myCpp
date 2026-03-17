#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* helper(vector<int>& preorder, int& prei, int left, int right, unordered_map<int, int>& mp) {

    if (left > right) return NULL;

    Node* root = new Node(preorder[prei++]);

    int inidx = mp[root->data];

    root->left = helper(preorder, prei, left, inidx - 1, mp);
    root->right = helper(preorder, prei, inidx + 1, right, mp);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {

    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    int prei = 0;

    return helper(preorder, prei, 0, inorder.size() - 1, mp);
}

void preorderprint(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}

int main() {

    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };

    Node* root = buildTree(preorder, inorder);

    preorderprint(root);

    return 0;
}

/*
 - - - LEETCODE VERSION - - -

class Solution {
public:

    unordered_map<int,int> mp;

    TreeNode* helper(vector<int>& preorder, int& prei, int left, int right){

        if(left > right) return NULL;

        TreeNode* root = new TreeNode(preorder[prei++]);

        int inidx = mp[root->val];

        root->left = helper(preorder, prei, left, inidx - 1);
        root->right = helper(preorder, prei, inidx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        int prei = 0;

        return helper(preorder, prei, 0, inorder.size() - 1);
    }
};*/