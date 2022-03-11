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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        
        ListNode* end=head;
        int count=1;
        while(end->next!=NULL){
            count++;
            end=end->next;
        }
        // cout<<count<<"\n";
        k=k>=count?(k%count):k;
        // cout<<k<<"\n";
        end->next=head;
        
        k=count-k-1;
        // cout<<k<<"\n";
        
        while(k--){
            head=head->next;
            cout<<head->val<<" ";
        }
        cout<<"\n";
        ListNode* temp=head->next;
        
        head->next=NULL;
        
        head=temp;
        
        return head;
        
        
        
        
        
        
    }
};