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
    void calculate(TreeNode* root,int sum,int &targetSum,vector<int> &ans,vector<vector<int>> &finalans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            if(sum + root->val == targetSum){
                finalans.push_back(ans);
            }
            ans.pop_back();
            return ;
        }
        ans.push_back(root->val);
        if(root->left != NULL) calculate(root->left,sum + root->val,targetSum,ans,finalans);
        ans.pop_back();
        ans.push_back(root->val);
        if(root->right != NULL) calculate(root->right,sum + root->val,targetSum,ans,finalans);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return {};
        int sum = 0 ;
        vector<int> ans;
        vector<vector<int>> finalans;
        calculate(root,sum,targetSum,ans,finalans);
        return finalans;
    }
};

/* PATH SUM 

Step 1 : While trversing maintaing the sum .
step 2 : During step 1 mainting the vector.
step 3 : Adding and removal of the element can be done
step 4 : if root left and right is null then it is leaf node -
         going to check the total sum from root node to leaf node 

         if (sum == targetsum ) 
         add ans vector to the final answer


*/