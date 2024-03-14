#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node *head;

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

Node* reverseList(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* new_head = prev;
    return new_head;
}


// Given the head of a singly linked list, reverse the list, and return the reversed list.
int main(){

    LinkedList ll; 
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();

    ll.head = reverseList(ll.head);
    ll.display();

    return 0;
}