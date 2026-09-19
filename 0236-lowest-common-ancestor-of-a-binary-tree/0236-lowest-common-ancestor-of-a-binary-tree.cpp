/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Check(TreeNode* root, TreeNode* p, TreeNode* q,bool &left,bool &right,TreeNode* &LCM){
        if(root == NULL) return;

        if(left == true && right == true ) return ;

        if(root == p || root == q){
            if(root == p) left = true;
            else right = true;

            if(left == true && right == true ) return ;
            else LCM = root;
        }

        if(LCM == NULL && (left == true || right == true)){
            LCM = root;
        }

        Check(root->left,p,q,left,right,LCM);
        if(left == true && right == true) return;

        if(LCM == NULL && (left == true || right == true ))
            LCM = root;

        Check(root->right,p,q,left,right,LCM);
        if(left == true && right == true) return;

        if(LCM == root && (left == true || right == true)){
            LCM = NULL;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* LCM = NULL;
        bool left = false;
        bool right = false;
        Check(root,p,q,left,right,LCM);
        return LCM;
    }
};