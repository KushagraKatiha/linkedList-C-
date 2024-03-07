#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

// insertion at head
void insertionAtHead(int data, Node* &head){
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

// Insertion at end
void insertionAtEnd(int val, Node* &head){

    Node* new_node = new Node(val);  
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

// insertion at arbitrary position
void insertAtKth(int val, int pos, Node* &head){

    if(pos == 0) {
        insertionAtHead(val, head);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int position = 0;

    while(position != pos-1){
        temp = temp->next;
        position++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"-> ";
        temp = temp->next;
    }   
    cout<<"NULL"<<endl;
}

int main(){

    Node* head = NULL;
    insertionAtHead(1, head);
    insertionAtHead(3, head);
    insertionAtEnd(5, head);
    insertionAtEnd(6, head);
    insertionAtEnd(7, head);
    insertAtKth(0, 3, head);
    display(head);

    return 0;
}