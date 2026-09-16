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
    void calculate(TreeNode* root,int sum,int &targetSum,bool &condition){
        if(condition == true) return ;
        if(root->left == NULL && root->right == NULL){
            if(sum + root->val == targetSum) condition = true;
            return ;
        }
        if(root->left != NULL) calculate(root->left,sum + root->val,targetSum,condition);
        if(root->right != NULL) calculate(root->right,sum + root->val,targetSum,condition);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int sum = 0 ;
        bool condition = false;
        calculate(root,sum,targetSum,condition);
        return condition;
    }
};