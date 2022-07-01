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
        
        ans+=(abs(left)+abs(right));
         
        root->val+=(left+right);
        
        return root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        
         ans=0;
         f(root);
         return ans;
        
        
        
    }
};