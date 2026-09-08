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
    TreeNode* value(TreeNode* root,int &val){
        if(root == NULL) return NULL;
        if(root->val == val) return root;
        else if(root->val < val) return value(root->right,val);
        else  return value(root->left,val);
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        return value(root,val);
    }
};

/* APPROACH - 

Binary Search Tree formation - 
   
    a) All the elements smaller than the root element should be placed left side
    b) All the elements greater than the root element should be placed right side 


1) search the element by the simple greater and smaller logic

A) if root element is equal return root
B) if root element is smaller search for the right side
C) if root element is greater search for the left side 
*/