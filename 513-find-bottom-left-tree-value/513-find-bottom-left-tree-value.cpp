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
    int height(TreeNode* root){
        
        if(root==NULL)return 0;
        
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        
        return 1+max(leftHeight,rightHeight);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)return 0;
        int level=height(root);
        
        int cnt=0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int ans;
        
        while(!q.empty()){
            
            int n=q.size();
            cnt++;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(cnt==level && i==0){ans=temp->val;
                                       break;}
                
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                
                
                
            }
            
            
            
            
            
        }
        
        
        
        
        
        
        
        
        return ans;
    }
};