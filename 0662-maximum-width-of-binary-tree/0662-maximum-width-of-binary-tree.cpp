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
    void leftside(TreeNode* root,int level,unsigned long long value,vector<unsigned long long> &leftvec){
        if(root == NULL) return;
        if(level == leftvec.size()) leftvec.push_back(value);
        
        leftside(root->left,level+1,value*2-1,leftvec);
        leftside(root->right,level+1,value*2,leftvec);
    }
    void rightside(TreeNode* root,int level,unsigned long long value,vector<unsigned long long> &rightvec){
        if(root == NULL) return;
        if(level == rightvec.size()) rightvec.push_back(value);
        
        rightside(root->right,level+1,value*2,rightvec);
        rightside(root->left,level+1,value*2-1,rightvec);
    }
    long long widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        vector<unsigned long long> leftvec;
        vector<unsigned long long> rightvec;
        leftside(root,0,1,leftvec);
        rightside(root,0,1,rightvec);
        unsigned long long maxi = 0;
        for(int i=0;i<leftvec.size();i++){
            maxi = max(maxi,rightvec[i]-leftvec[i]+1);
        }
        return maxi;
    }
};