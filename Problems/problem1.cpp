#include<iostream>
using namespace std;

// Given the head of a linked list, delete every alternate element from the list starting from the second element.
class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
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

void deleteAlternate(Node* &head){
    Node* curr_node = head;

    while(curr_node != NULL and curr_node->next != NULL){
        Node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
}

int main(){
    Node* head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);
    deleteAlternate(head);
    display(head);
    return 0;
}