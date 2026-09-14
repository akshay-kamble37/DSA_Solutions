#include <climits>
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
    long long calculate(TreeNode* root,long long &maxi){
        if (root == NULL)
            return 0;

        long long left_sum = calculate(root->left, maxi);
        long long right_sum = calculate(root->right, maxi);
        long long left = max(0LL, left_sum);
        long long right = max(0LL, right_sum);
        long long current = (long long)root->val + left + right;
        maxi = max(maxi, current);
        return (long long)root->val + max(left, right);
    }
    long long maxPathSum(TreeNode* root) {
       long long maxi = LLONG_MIN;

        calculate(root, maxi);

        return maxi;
    }
};


/* Approach : 

step 1 : Check the left sum and right sum for each node 
step 2 : calculating maximum sum at each node and storing it.
step 3 : Returning the node value with maximum value from (left_sum,right_sum).
step 4 : step 3 because node can not be repeat.

*/