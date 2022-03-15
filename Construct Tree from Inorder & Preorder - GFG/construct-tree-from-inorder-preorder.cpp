// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    map<int,int> m;
    Node* solve(int in[],int inStart,int inEnd,int pre[],int preStart,int preEnd){
        
        if(inStart>inEnd || preStart>preEnd)return NULL;
        
        Node* root=new Node(pre[preStart]);
        
        int partition=m[root->data];
        int c=partition-inStart;
        
        root->left=solve(in,inStart,partition-1,pre,preStart+1,preStart+c);
        root->right=solve(in,partition+1,inEnd,pre,preStart+c+1,preEnd);
        
        return root;
        
        
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        return solve(in,0,n-1,pre,0,n-1);
        
        
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends