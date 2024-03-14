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

class linkedList{
    public: 
    Node* head;

    linkedList(){
        head=NULL;
    }

    void insertAtHead(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }

    void insertAtTail(int val){
        Node* new_node = new Node(val);
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

    void deleteDuplicates(){
        Node* curr = head;

        while(curr){
            while(curr->next && curr->val == curr->next->val){
                Node* temp = curr->next;
                // remove next element to curr
                curr->next = curr->next->next;
                free(temp);
            }
            curr = curr->next;
        }
    }
};

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorte as well.

int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(5);
    ll.insertAtTail(5);
    ll.insertAtTail(5);
    ll.display();
    ll.deleteDuplicates();
    ll.display();
    return 0;
}