#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next= NULL;
    }
};

void InsertEleAt_head(Node* &head,int value){
    Node* new_node= new Node(value);
    new_node->next=head;
    head=new_node;
}

//ek problem hai if i add element to the tail in an  empty ll tooh problem aa jaegi
void insertELeAt_tail(Node* &head, int value){
    Node* new_node= new Node(value); // iske next me already NULL hai kyuki Node class ka constructor
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next= new_node;
    
}

void display_Node(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL" << endl;

}

void insertEleAt_Kpos(Node* &head, int value,int pos){
    if(pos==0){
        InsertEleAt_head(head,value);
        return;
    }
    else{
        Node* new_node= new Node(value);
        Node* temp = head;
        int count=0;
        while(count!=pos-1){
            temp=temp->next;
            count++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void update_k(Node* &head,int value,int pos){
    Node* temp = head;
    int count=0;
    while(count!=pos){
        temp=temp->next;
        count++;
    }
    temp->data=value;
}

void delete_head(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void delete_tail(Node* &head){
    Node* second_last= head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    Node* temp = second_last->next;
    second_last->next=NULL;
    free(temp);
}

void delete_k(Node* &head,int pos){
    Node *temp=head;
    int count=0;
    while(count!=pos-1){
        count++;
        temp=temp->next;
    }
    Node* free_up=temp->next;
    temp->next=temp->next->next;
    free(free_up);

}

int main(){
    Node* head = NULL;
    InsertEleAt_head(head,1);
    // display_Node(head);
    InsertEleAt_head(head,2);
    // display_Node(head);
    InsertEleAt_head(head,5);
    // display_Node(head);
    insertELeAt_tail(head,4);
    //insertELeAt_tail(head,9);
    // display_Node(head);
    InsertEleAt_head(head,6);
    //display_Node(head);
    insertEleAt_Kpos(head,8,2);
    //display_Node(head);
    update_k(head,3,2);
    // display_Node(head);
    // delete_head(head);
    // display_Node(head);
    // delete_k(head,1);
    display_Node(head);
}