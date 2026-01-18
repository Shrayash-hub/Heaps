/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    class compare{
        public:
            bool operator()(Node* a,Node* b){
                return a->data > b->data;
            }
    };
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<Node*, vector<Node*>, compare> p(arr.begin(),arr.end());
        
        Node* root = new Node(0);
        Node* tail = root;
        
        while(!p.empty()){
            Node* temp = p.top();
            tail->next = temp;
            p.pop();
            tail = tail->next;
            if(temp->next)
            p.push(temp->next);
        }
        return root->next;
    }
};