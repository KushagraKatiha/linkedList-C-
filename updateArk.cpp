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

void insertAtHead(int val, Node* &head){
    Node* new_node = new Node(val);
    new_node->next = head;

    head = new_node;
}

void insertionAtEnd(int val, Node* &head){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

// Updation at kth position
void updateAtKth(int updateVal, int pos, Node* &head){
    if(pos == 0){
        head->val = updateVal;
        return;
    }

    Node* temp = head;
    int curr_pos = 0;

    while(curr_pos < pos-1){
        temp = temp->next;
        curr_pos++;
    }

    temp->val = updateVal;
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
    insertAtHead(3, head);
    insertAtHead(2, head);
    insertAtHead(5, head);
    insertAtHead(1, head);
    updateAtKth(0, 3, head);
    display(head);

    return 0;
}