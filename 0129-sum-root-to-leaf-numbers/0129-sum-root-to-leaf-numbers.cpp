/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void calculate(TreeNode* root,long long current,long long &num){
        if(root->left == NULL && root->right == NULL){
            num += current+root->val;
            return ;
        }
        current += root->val ;
        if(root->left != NULL){
            calculate(root->left,current*10,num);
        }
        if(root->right != NULL){
            calculate(root->right,current*10,num);
        }
        return ;
    }
    long long sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        long long num = 0;
        calculate(root,0,num);
        return num;
    }
};