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
    void check(TreeNode* L,TreeNode* R,bool &status){
        if(status == false) return;
        if( (L == NULL && R != NULL ) || (L != NULL && R==NULL)){
            status = false;
            return ;
        }
        if(L == NULL) return;
        if(R == NULL) return;
        if(L->val != R->val){
            status = false;
            return ;
        }

        check(L->left,R->right,status);
        check(L->right,R->left,status);

    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(root->left != NULL && root->right != NULL){
            bool status = true;
            check(root->left,root->right,status);
            return status;
        }
        return false;
    }
};


/* Approach : 

step 1 : Checking the factors 
step 2 : Divide the tree in two segments
step 3 : Those two tree travelling completely opposite to each other 
step 4 : if tree-> val not match return false

*/