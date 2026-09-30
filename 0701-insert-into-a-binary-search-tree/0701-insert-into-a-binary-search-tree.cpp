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
    void add(TreeNode* root, int val,bool &status){
        if(status == true) return;
        if(root->val > val){
            if(root->left != NULL){
                add(root->left,val,status);
            }else{
                TreeNode* tree = new TreeNode(val);
                root->left = tree;
                status = true;
                return;
            }
        }else{
            if(root->right != NULL){
                add(root->right,val,status);
            }else{
                TreeNode* tree = new TreeNode(val);
                root->right = tree;
                status = true;
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* tree = new TreeNode(val);
            return tree;
        }
        bool status = false;
        add(root,val,status);
        return root;
    }
};