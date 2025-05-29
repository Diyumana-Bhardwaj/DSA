#include <iostream>
#include <vector>
using namespace std;

/*template <typename T>
class Node{
    public:
    T data;
    Node* next;
    Node(T val){
        data=val;
        next=NULL;
    }
};*/
// int main(){
//     Node<int>* node1= new Node<int> (3);
//     cout<<node1->data<<endl;

//     Node<char>* node2=new Node<char> ('a');
//     cout<<node2->data<<endl;
// }

//stacks
//using array

class stack1{
    private:
    int capacity;
    int* arr;
    int top_index;

    public:
    stack1(int c){
        this->capacity=c;
        arr = new int[capacity];
        this->top_index= -1;
    }
    void push(int val){
        if(this->top_index==this->capacity-1){
            cout<<"overflow\n";
            return;
        }
        this->top_index++;
        this->arr[this->top_index]=val;
    }
    
    void pop(){
        if(this->top_index==-1){
            cout<<"underflow\n";
            return;
        }
        this->top_index--;
    }
    bool isempty(){
        return (this->top_index==-1);
    }
    bool isfull(){
        return (this->top_index==this->capacity-1);
    }
    int size(){
        return (this->top_index+1);
    }
    int top(){
        if(this->top_index==-1){
            cout<<"underflow\n";
            return INT_MIN;
        }
        return this->arr[this->top_index];
    }
    void display(){
        int temp=this->top_index;
        while(temp!=-1){
            cout<<arr[temp]<<endl;
            temp--;
        }
    }
};

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class Stack2{
    Node* head;
    int capacity;
    int top_indx;

    public:
    Stack2(int c){
        this->capacity=c;
        this->top_indx=0;
        head=NULL;
    }
    void push(int value){
        if(this->top_indx==this->capacity){
            cout<<"Overflow\n";
            return;
        }
        Node* new_node= new Node(value);
        new_node->next=head;
        head=new_node;
        this->top_indx++;
    }
    void pop(){
        if(this->top_indx==0){
            cout<<"Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        free(temp);
        this->top_indx--;
    }
    bool isempty(){
        return (this->top_indx==0);
    }
    bool isfull(){
        return (this->top_indx==this->capacity);
    }
    int size(){
        return top_indx;
    }
    int top(){
        return head->data;
    }
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

// stack using STL
#include <stack>
int main(){
    stack<int> st; //no size
    st.pop();
    // stack1 S1(5);
    // S1.push(12);
    // S1.push(10);
    // S1.push(9);
    // S1.push(2);
    // S1.push(1);
    // S1.pop();
    // //cout<<S1.size();
    // //S1.display();
    // return 0;

    // Stack2 S2(5);
    // S2.push(1);
    // S2.push(2);
    // S2.push(3);
    // S2.display();


}
