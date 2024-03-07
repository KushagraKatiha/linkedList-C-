#include<iostream>
using namespace std;
// Implementation of a singly linked list

class Node{
    public:
        int val;
        Node* next;

    Node(int x){
        val = x;
        next = NULL;
    }
};

int main(){

    Node * n = new Node(1);

    cout<<n->val<<"-> "<<n->next<<endl;;

    return 0;
}