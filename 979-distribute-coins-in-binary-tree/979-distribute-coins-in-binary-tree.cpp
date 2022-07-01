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
    int ans;
public:
    int f(TreeNode* root){
       
        if(root==NULL)return 0;
        
        int left=f(root->left);
        int right=f(root->right);
        

        
        if(left>0){
            ans+=left;
            root->val+=left;
        }
        if(right>0){
            ans+=right;
            root->val+=right;
        }
        
        if(right<0){
            ans-=right;
            root->val+=right;
        }
        if(left<0){
            ans-=left;
            root->val+=left;
        }
        
        return  root->val==1?0:root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        
         ans=0;
         f(root);
         return ans;
        
        
        
    }
};