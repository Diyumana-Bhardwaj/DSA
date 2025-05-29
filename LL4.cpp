#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class CircularLinkedList{
    public:
    Node* head;

    CircularLinkedList(){
        head=NULL;
    }

    void Insert_at_start(int value){
        Node* new_node= new Node(value);
        if(head==NULL){
            head=new_node;
            new_node->next=head;
            return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=new_node;
        new_node->next=head;
        head=new_node;
    }

    void print_cilcular(){
        Node* temp=head;
        while(true){
            cout<<temp->data<<"->";
            temp=temp->next;
            if(temp==head) break; //else use do while loop
        }
    }
    void Insert_at_end(int value){
        Node* new_node= new Node(value);
        if(head==NULL){
            head=new_node;
            new_node->next=head;
            return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=new_node;
        new_node->next=head;
    }

    void Insert_at_kth(int value,int pos){
        Node* new_node= new Node(value);
        if(pos==0){
            Insert_at_start(value);
            return;
        }
        Node* temp=head;
        int count=1;
        while(count!=pos){
            temp=temp->next;
            count++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
};
// updation and deletion is same
//deletion of head and tail is bit imp
int main(){
    CircularLinkedList C1;
    C1.Insert_at_start(5);
    C1.Insert_at_start(4);
    C1.Insert_at_start(3);
    C1.Insert_at_start(2);
    C1.Insert_at_start(1);
    C1.Insert_at_end(12);
    C1.Insert_at_kth(22,7);
    C1.print_cilcular();
}
