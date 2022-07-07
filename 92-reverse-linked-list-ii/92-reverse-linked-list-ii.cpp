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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* start=NULL;
        ListNode* end=NULL;   
        int count=1;
        ListNode* temp=head;
        ListNode* reverseStart=NULL;
        while(temp){
            
            if(count==(left-1)){
                start=temp;
            }
            if(count==(right+1)){
                end=temp;
            }
            if(count==left){
                reverseStart=temp;
            }
            count++;
            temp=temp->next;
            
        }
        
        ListNode* prev=NULL;
        temp=reverseStart;
        while(left<=right && temp){
            
            ListNode* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
            
            left++;
        }
        
        
        if(start){        
        start->next=prev;
        }
        else{
            head=prev;
        }
        while(prev->next){
            prev=prev->next;
            
        }
        prev->next=end;
        
        return head;
        
    }
};