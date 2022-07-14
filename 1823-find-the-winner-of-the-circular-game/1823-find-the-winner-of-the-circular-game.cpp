class Node{
    
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }    
};
class Solution {
public:
    
    int findTheWinner(int n, int k) {
        //  =1 -1 3 -1 -1
        //  1 -1 -1 -1 -1 -1
        
        // 1 2 3 4 5 6 
        // 1 2 3 4 6
        // 1 2 3 6
        // 1 2 3
        // 1 3
        // 1 3
        
        int count=1;
        
        Node* start=NULL;
        Node* prev=NULL;
        Node* temp;
        
        while(count<=n){
            
            Node* newNode=new Node(count);
            if(start==NULL){
                start=newNode;
                temp=start;
            }
            else{
                temp->next=newNode;
                temp=newNode;
            }
            
            count++;
        }
        
        temp->next=start;
        
        prev=temp;
        temp=start;
        
        while(temp!=prev){
            
            int counter=k;
            while(--counter){
                prev=temp;
                temp=temp->next;
            }
            
            prev->next=temp->next;
            temp=prev->next;
            
            
        }
        
        return temp->val;
        
    }
};