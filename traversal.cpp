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

void insertionAtHead(int data, Node* &head){
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
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
    insertionAtHead(5, head);
    display(head);

    insertionAtHead(15, head);
    display(head);

    return 0;
}