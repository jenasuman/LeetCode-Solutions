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
    TreeNode* solve(TreeNode* root,int target){
        if(root==NULL)return NULL;
        
        if(root->val==target)return root;
        
        TreeNode* left=solve(root->left,target);
        TreeNode* right=solve(root->right,target);
        
        if(left!=NULL)return left;
        if(right!=NULL)return right;
        
        return NULL;
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(target==NULL)return NULL;
        int targetVal=target->val;
        return solve(cloned,targetVal);
        
    }
};