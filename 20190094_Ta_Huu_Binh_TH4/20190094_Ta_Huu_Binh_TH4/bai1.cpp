#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* new_node =  new Node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// print the list content on a line
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* cur = head->next;
    Node* prev = head;
    prev -> next = NULL;
    while (cur != NULL){
        Node* next = cur->next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}