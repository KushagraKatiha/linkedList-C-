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

class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head = NULL;
    }  

    void insertAtHead(int data){
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insertAtTail(int data){
    Node* new_node = new Node(data);
    if(head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}


    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void printInReverse(Node* head){
    if(head == NULL) return;
    printInReverse(head->next);
    cout<<head->val<<"-> ";
}

// Given the head of a singly linked list, print the reversed list.
int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();

    printInReverse(ll.head);

    return 0;
}