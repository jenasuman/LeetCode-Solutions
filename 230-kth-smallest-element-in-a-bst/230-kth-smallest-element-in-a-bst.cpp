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
    int ans=-1;
    
    TreeNode* solve(TreeNode* root,int& k){
        if(root==NULL)return NULL;
        
        
       
        TreeNode* node_left=solve(root->left,k);
        
        
            k--;
            if(k==0){
            ans=root->val;
            return root;
            }
        
       
        TreeNode* node_right=solve(root->right,k);
        
     
        
        return root;
        
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        
        
        solve(root,k);
        
        return ans;
        
        
    }
};