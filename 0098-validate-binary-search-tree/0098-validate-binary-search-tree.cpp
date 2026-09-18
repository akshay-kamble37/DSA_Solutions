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
    void check(TreeNode* root,bool &status,long long low,long long high){
        if (root == NULL || status == false)
        return;

        if (root->val <= low || root->val >= high) {
            status = false;
            return;
        }

        check(root->left, status, low, root->val);
        check(root->right, status, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        bool status = true;

        check(root, status, LLONG_MIN, LLONG_MAX);

        return status;
    }
};

/* APPROACH -

step 1 : checking the current node first - 
        if node left and node right is null then the node correct or valid binary tree node
step 2 : check the node left - 
        if it is null then check right node
        else - check for the left node value .. if it is smaller than the current node value then move to the left node
                                                else status = false and return 

step 3 : check the node right - 
        if it is null then return 
        else - check for the right node value .. if it is greater than the current node value then move to the right node
                                                else status = false and return
*/

