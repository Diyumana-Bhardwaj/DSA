#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=NULL;
        prev= NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }

    void InsertAt_tail(int value){
        Node* new_node=new Node(value);
        if (head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }

    void InsertAt_Start(int value){
        Node* new_node=new Node(value);
        if (head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }

    void display(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp= temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void display_reverse(Node* &tail){
        Node* temp = tail;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp= temp->prev;
        }
        cout<<"NULL"<<endl;
    }

    void insertAt_kth( int value,int pos){
        Node* new_node= new Node(value);
        if(pos==0){
            InsertAt_Start(value);
            return;
        }
        Node* temp=head;
        int count=1;
        while(count!=pos){
            temp=temp->next;
            count++;
            if(temp->next==NULL){
                InsertAt_tail(value);
                return;
            }
        }
        new_node->prev=temp;
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
    }

    void delete_kth(int pos){
        Node* temp=head;
        if(pos==0){
            head=head->next;
            head->prev=NULL;
            free(temp);
            return;
        }
        int count=0;
        while(count!=pos-1){
            count++;
            temp=temp->next;
        }
        Node* free_up=temp->next;
        temp->next=temp->next->next;
        temp->next->prev=temp;
        free(free_up);
    }

    void delete_kth_end(int pos){
        Node* temp=tail;
        if(pos==0){
            tail=tail->prev;
            tail->next=NULL;
            free(temp);
            return;
        }
        int count=0;
        while(count!=pos-1){
            count++;
            temp=temp->prev;
        }
        Node* free_up=temp->prev;
        temp->prev=temp->prev->prev;
        temp->prev->next=temp;
        free(free_up);
    }
};

//ques1 given an head of doubly linked list reverse it

void reverse(Node* &head,Node* &tail){
    Node* curr=head;
    while(curr){
        Node* temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        curr=temp;
    }
    Node* temp=head;
    head=tail;
    tail=temp;
}

//palindrome
bool palindrome(Node* head,Node* tail){
    while(head!=tail && tail!=head->prev){
        if(head->data!=tail->data) return false;
        head=head->next;
        tail=tail->prev;
    }
    return true;
}

//delete the node whose neighbours are same access right to left
void delete_neigh(Node* head,Node*tail){
    Node* curr= tail->prev;
    while(curr!=head){
        Node* prev_node= curr->prev;
        Node* next_node=curr->next;
        if(prev_node->data==next_node->data){
            prev_node->next=next_node;
            next_node->prev=prev_node;
            free(curr);
        }
        curr=prev_node;
    }
}

//ques from video critical point ques
//local maxima when the neighbouring value is smaller
#include<vector>

bool isCriticalPoint(Node* &curr){
    Node* prev_node= curr->prev;
    Node* next_node=curr->next;
    if(prev_node->data>curr->data&& next_node->data>curr->data){
        return true;
    }

    if(prev_node->data<curr->data&& next_node->data<curr->data){
        return true;
    }
    return false;
}
vector<int> min_max_dis(Node* tail){
    vector<int> ans(2,INT_MAX);

    Node* curr= tail->prev;
    if(curr==NULL){
        ans[0]=ans[1]=-1;
        return ans;
    }   

    int first=-1,last=-1,pos=0;
    while(curr->prev!=NULL){
        if(isCriticalPoint(curr)){
            if(first==-1) first=pos;
            else{
                ans[0]=min(ans[0],pos-last); // min
                ans[1]=pos-first; //max
            }
            last=pos;
        }
        pos++;
        curr=curr->prev;
    }
    //if only 1 CP
    if(ans[0]==INT_MAX) ans[0]=ans[1]=-1;
    return ans;
}

//sum  od two
vector<int> sum(Node* head,Node* tail,int x){
    vector<int> ans(2,-1);
    while(head!=tail){
        int sum=head->data+tail->next->data;
        if(sum==x){
            ans[0]=head->data;
            ans[1]=tail->data;
            return ans;
        }
        //i need smaller value,i will move my tail back
        if(sum>x) tail=tail->prev;
        else head=head->next;
    }
    return ans;
}

int main(){
    DoublyLinkedList D1;
    D1.InsertAt_tail(1);
    D1.InsertAt_tail(2);
    D1.InsertAt_tail(3);
    D1.InsertAt_tail(4);
    D1.insertAt_kth(9,2);

    //D1.display(D1.head);

    D1.delete_kth(0);
    reverse(D1.head,D1.tail);
    //D1.display(D1.head);
    //D1.display_reverse(D1.tail);

    DoublyLinkedList D2;
    D2.InsertAt_Start(9);
    D2.InsertAt_Start(8);
    D2.InsertAt_Start(7);
    D2.InsertAt_Start(6);

    //D2.display(D2.head);

    D2.delete_kth_end(0);
    //D2.display(D2.head);
    //D2.display_reverse(D2.tail);

    DoublyLinkedList D3;
    D3.InsertAt_tail(1);
    D3.InsertAt_tail(2);
    D3.InsertAt_tail(3);
    D3.InsertAt_tail(2);
    D3.InsertAt_tail(1);
    //cout<<palindrome(D3.head,D3.tail);

    DoublyLinkedList D4;
    D4.InsertAt_tail(2);
    D4.InsertAt_tail(1);
    D4.InsertAt_tail(1);
    D4.InsertAt_tail(2);
    D4.InsertAt_tail(1);

    //D4.display(D4.head);

    delete_neigh(D4.head,D4.tail);
    //D4.display(D4.head);

    DoublyLinkedList D5;
    D5.InsertAt_tail(1);
    D5.InsertAt_tail(5);
    D5.InsertAt_tail(2);
    D5.InsertAt_tail(6);
    D5.InsertAt_tail(3);
    D5.InsertAt_tail(11);
    D5.InsertAt_tail(3);

    vector<int> ans=min_max_dis(D5.tail);
    cout<<ans[0]<<" "<<ans[1];
}
