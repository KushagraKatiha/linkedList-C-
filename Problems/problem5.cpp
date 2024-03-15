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

    void insertAtHead(int val){
        Node* new_node = new Node(val);

        new_node->next = head;
        head = new_node;
    }

    void insertAtTail(int val){
        Node* new_node = new Node(val);

        if(head == NULL){
            insertAtHead(val);
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

Node* reverseListUsingRecursion(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* new_head = reverseListUsingRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

// Reverse the linked list using recursion
int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);

    ll.display();
    return 0;
}