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
    void check(TreeNode* root,int level,vector<int> &vec){
        if(root == NULL) return ;
        if(level == vec.size()) vec.push_back(root->val);

        check(root->left,level+1,vec);
        check(root->right,level+1,vec);

    }
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return -1;
        int level = 0 ;
        vector<int> vec;
        check(root,level,vec);
        return vec.back();
    }
};