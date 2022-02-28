/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> m2;
    Node* solve(Node* node){
        
      Node* temp=new Node(node->val);
      m2[temp->val]=temp;
      for(auto c:node->neighbors){
          
          if(m2.find(c->val)!=m2.end()){
              temp->neighbors.push_back(m2[c->val]);
          }
          else{
              solve(c);
              temp->neighbors.push_back(m2[c->val]);
              
          }
     
          
          
      }
      
      return temp; 
        
        
    }
    Node* cloneGraph(Node* node) {
        
     if(node==NULL)return NULL;
       
      return solve(node);  
        
        
        
    }
};