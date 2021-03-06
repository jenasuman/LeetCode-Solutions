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
    int notNeeded=0;
    int noCamera=2;
    int hasCamera=1;
    int ans;
    int f(TreeNode* root){
        
        if(root==NULL)return notNeeded;
        
        int l=f(root->left);
        int r=f(root->right);
        
        if(l==noCamera || r==noCamera){
            
            ans++;
            return hasCamera;
        }
        else if(l==hasCamera || r==hasCamera){
            return notNeeded;
        }
       
        return noCamera;
        
        
        
        
    }
    
    
    int minCameraCover(TreeNode* root) {
        
        ans=0;
        
        if(f(root)==noCamera)ans++;
        
        return ans;
        
        
        
        
        
    }
};