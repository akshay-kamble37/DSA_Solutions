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
    void calculate(TreeNode* root,int l,int r,int& sum){
        if(root == NULL) return ;
        if(l == 1 && root->left == NULL && root->right == NULL){
            sum += root->val ;
            return;
        }

        if(root->left != NULL) calculate(root->left,1,r,sum);
        if(root->right != NULL) calculate(root->right,0,r,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL || root->left == NULL && root->right == NULL ) return 0;
        int l=0;
        int r=0;
        int sum  = 0;
        calculate(root,l,r,sum);
        return sum;
    }
};