/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size=0;
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            
            size++;
            temp=temp->next;
            
        }
        
        int firstIndex=k;
        int lastIndex=size-k+1;
        cout<<firstIndex<<" "<<lastIndex<<"\n";
        ListNode* firstNode;
        ListNode* secondNode;
        
        temp=head;
        
        for(int i=1;i<=(size);i++){
            if(i==k)firstNode=temp;
            if(i==(size-k+1))secondNode=temp;
            temp=temp->next;
        }
        
        int x=firstNode->val;
        firstNode->val=secondNode->val;
        secondNode->val=x;
        
        return head;
        
        
    }
};