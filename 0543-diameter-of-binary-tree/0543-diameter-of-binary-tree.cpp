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
    int calculate(TreeNode* root,int &maxi){
        if(root == NULL) return -1;
        int left = calculate(root->left,maxi) + 1;
        int right = calculate(root->right,maxi) + 1;

        maxi = max(left + right , maxi);

        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return -1;
        int maxi = 0;
        calculate(root,maxi);
        return maxi;
    }
};