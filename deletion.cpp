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

// Insertion at head
void insertionAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    
    head = new_node;    
}

// Insertion at end
void insertionAtEnd(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = NULL;
}

// Insertion at kth position
void insertionAtKth(Node* &head, int val, int pos){
    Node* new_node = new Node(val);
    Node* temp = head;

    if(pos == 0){
        insertionAtHead(head, val);
        return;
    }

    int curr_pos = 0;
    while(curr_pos != pos-2){       // considering indexing from 1
        temp = temp->next;
        curr_pos++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// void deleteion at head
void deletionAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

// deletion at end
void deletionAtEnd(Node* &head){
    Node* second_last = head;

    while(second_last -> next -> next != NULL){
        second_last = second_last->next;
    }

    Node* temp = second_last->next;
    second_last->next = NULL;
    free(temp);
}

// deletion at kth
void deletionAtKth(Node* &head, int pos){
    if(pos == 0){
        deletionAtHead(head);
        return;
    }

    Node* requiredNode = head;
    int curr_pos = 0;

    while(curr_pos < pos-2){        //considering indexing from 1
        requiredNode = requiredNode->next;
        curr_pos++;
    } 

    Node* temp = requiredNode->next;
    requiredNode->next = requiredNode->next->next;

    free(temp);
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

    insertionAtHead(head, 5);
    insertionAtHead(head, 4);
    insertionAtHead(head, 3);
    insertionAtHead(head, 2);
    insertionAtHead(head, 1);
    display(head);
    insertionAtEnd(head, 7);
    insertionAtEnd(head, 8);
    insertionAtEnd(head, 9);
    display(head);
    insertionAtKth(head, 6, 6);
    display(head);
    deletionAtHead(head);
    display(head);
    deletionAtEnd(head);
    display(head);
    deletionAtKth(head, 3);
    display(head);
    return 0;
}