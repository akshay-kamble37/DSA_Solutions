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
    void counting(TreeNode* root,int &value,int count){
        count++;
        if(root->left == NULL && root->right == NULL){
            value = min(value,count);
            return;
        }
        if(root->left != NULL) counting(root->left,value,count);
        if(root->right != NULL) counting(root->right,value,count); 
    }

    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int value = INT_MAX;
        int count = 0;
        counting(root,value,count);

        return value;       
    }
};