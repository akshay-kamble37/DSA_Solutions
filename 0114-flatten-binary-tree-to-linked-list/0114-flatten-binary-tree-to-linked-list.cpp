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
    void preorder(TreeNode* root,vector<TreeNode*> &ans){
        if(root == NULL) return ;
        
        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    void flatten(TreeNode* root) {
        if(root == NULL ) return;
        TreeNode* current = root;
        vector<TreeNode*> ans;
        preorder(root,ans);
        ans.erase(ans.begin());

        root = current;
        for(auto it:ans){
            root->left = NULL;
            root->right = it;
            root = root->right;
        }
        return ;
    }
};
