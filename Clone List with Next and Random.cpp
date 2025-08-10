class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* temp = head;
        
        while(temp){
            Node* newNode = new Node(temp -> data);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            temp = temp -> next -> next;
        }
        
        temp = head;
        while(temp){
            Node* newNode = temp -> next;
            newNode -> random = (temp -> random) ? temp -> random -> next : nullptr;
            temp = temp -> next -> next;
        }
        
        Node* dummy = new Node(0);
        Node* res = dummy; temp = head;
        while(temp){
            dummy -> next = temp -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
            dummy = dummy -> next;
        }
        
        return res -> next;
    }
};
