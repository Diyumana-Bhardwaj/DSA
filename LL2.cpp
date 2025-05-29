#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //for line 153
    bool visited;

    Node(int val){
        data=val;
        next= NULL;
    }
};

class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head = NULL;
    }
    void InsertAt_tail(int value){
        Node* new_node= new Node(value);
        if(head==NULL){ //linkedlist is empty
            new_node->next=head;
            head=new_node;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next= new_node;
    }

    void display(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp= temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

// ques given head of the linked list, delete every alternative ele from starting from the scond ele
/* if no of elements are even condition == current_node==null
if no of elements are odd condtion == current_node->next==null
*/
void delete_alternative(Node* &head){
    Node* current_node = head;
    while(current_node!=NULL && current_node->next!=NULL){
        Node* temp = current_node->next;
        current_node->next=current_node->next->next;
        free(temp);
        current_node=current_node->next;
    }
}

//delete duplicate from the LL
void delete_duplicate(Node* &head){
    Node* current_node = head;
    while(current_node!=NULL && current_node->next!=NULL){
        if(current_node->data==current_node->next->data){
            Node* temp=current_node->next;
            current_node->next=current_node->next->next;
            free(temp);
        }
        else{
            current_node=current_node->next;
        }
    }
}

// print LL in reverse order without actually reversing it
void display_reverse(Node* &head){
    if(head==NULL) return;
    display_reverse(head->next);
    cout<<head->data<<" ";
}

// reverse the linked list completely and display it
// method 1 reverse the links
Node* reverse1(Node* &head){
    Node* pre=NULL;
    Node* current = head; // ek aur tarika hai head ko by refrence na pass karke as value kardo new variable nhi bana padega
    while(current!=NULL){
        Node* temp=current->next;
        current->next=pre;
        pre=current;
        current=temp;

    }
    // when this loop end pre ptr will point to last node and head is still fist change head!
    Node* new_head=pre;
    return new_head;
}
//main of this function
/*
L1.head=reverse1(L1.head);
L1.display(L1.head);*/

//method 2 using recursion samajh nhi aya
Node* reverse2(Node* &head){
    if(head->next==NULL || head==NULL) return head; //empty or single element
    Node* new_head=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;//head is now pointing to last node in LL
    return new_head;
}

//given the head of the linked list reverse the nodes k at a time
Node* reverse_kAtTime(Node* &head,int k){
    if(head->next==NULL || head==NULL) return head; //empty or single element
    int count=0;
    Node* current=head;
    Node* pre=NULL;
    while(count!=k && current!=NULL){
        Node* temp=current->next;
        current->next=pre;
        pre=current;
        current=temp;
        count++;
    }
    if(current!=NULL){
        Node* new_head=reverse_kAtTime(current,3); // error why
        head->next=new_head;
    }
    return pre;
}
//2 pointer check 2 linked list equal or not
bool check_equal(Node* &head1,Node* &head2){
    if((head1==NULL && head2!=NULL) || (head1!=NULL && head2==NULL)) return false;
    if(head1==NULL && head2==NULL) return true;
    if(head1->data==head2->data)
    return check_equal(head1->next,head2->next);
    return false;
}
//iterative method
bool checkEqualLinkedList(Node* &head1,Node* &head2){
    Node* ptr1=head1;
    Node* ptr2= head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data!=ptr2->data) return false;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    //at this point either ptr1 is null or ptr2 or both null
    return(ptr1==NULL && ptr2==NULL);
}

//given the head of two LL return node at which two lists intersect , if not return null
// isme problem yeah hai ki agar equal position par ho tab hi milenge agar diffrenec of possition ka toh nhi milenge
int check_intersect(Node* headA, Node* headB){
    Node* ptr1=headA;
    Node* ptr2= headB;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data==ptr2->data) return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
//ek tarika hai each element of head A ke liye check full list B T(m*n)
// method 2 changes in class nodeT(m+n)
int check_intersection(Node* headA, Node* headB){
    Node* ptr1=headA;
    Node* ptr2= headB;
    while(ptr1!=NULL){
        ptr1->visited=true;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        if(ptr2->visited==true) return ptr2->data;
        ptr2=ptr2->next;
    }
    return -1;
}

// method 3 using set O(n+m)
//method 4 bring pointers to the equal distance to the par le aau
int get_length(Node* headA){
    Node* temp=headA;
    int count=1;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int find_intersection(Node* headA, Node* headB){
    Node* ptr1=headA;
    Node* ptr2= headB;
    int countA=get_length(headA);
    int countB=get_length(headB);
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data==ptr2->data) return ptr1->data;
        if(countA>countB){
            ptr1=ptr1->next;
            countA--;
        }
        if(countB>countA){
            ptr2=ptr2->next;
            countB--;
        }
        else{
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    return -1;
}

// delete the kth node from end using 2 pointer or traversing only 1 time
void delete_K_fromEnd(Node* &head,int k){
    Node* ptr1=head;
    Node* ptr2=head;
    while(k--){
        ptr2=ptr2->next;
    }
    while(ptr2->next!=NULL){
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }

    //ptr1 will now point to k-1th node from end
    Node* temp = ptr1->next;
    ptr1->next= ptr1->next->next;
    free(temp);
}
// creation of new LL of same elem 
Node* mergeLL(Node* headA, Node* headB){
    Node* ptr1=headA;
    Node* ptr2= headB;
    LinkedList L_merge;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            L_merge.InsertAt_tail(ptr1->data);
            ptr1=ptr1->next;
        }
        else{
            L_merge.InsertAt_tail(ptr2->data);
            ptr2=ptr2->next;
        } 
            
    }
    while(ptr1!=NULL){
        L_merge.InsertAt_tail(ptr1->data);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        L_merge.InsertAt_tail(ptr2->data);
        ptr2=ptr2->next;
    }
    return L_merge.head;
}
// creation of LL with changinging links in existing LL
Node* dummy_head(Node* headA, Node* headB){
    Node* dummy_headNode = new Node(-1);
    Node* ptr1=headA;
    Node* ptr2= headB;
    Node* ptr3=dummy_headNode;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
        
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    Node* temp = dummy_headNode;
    dummy_headNode=dummy_headNode->next;
    free(temp);
    return dummy_headNode;
}
#include <vector>
//given an array of k linked list list each LL is sorted merge all in sorted order
void merge_multipleLL(vector<Node*> &lists){
    while(lists.size()!=1){
        Node* head = dummy_head(lists[0],lists[1]);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
        lists.push_back(head);
    }
}
//slow fast pointer
// find middle eelement of the LL
int middle_element(Node* & head){
    Node* ptr1=head;
    Node* ptr2=head;
    int ptr2_pos = 0,ptr1_pos=0;
    while(ptr2!=NULL){
        ptr2=ptr2->next;
        ptr2_pos++;
        int n=((ptr2_pos)/2)-ptr1_pos;
        while(n--){
            ptr1=ptr1->next;
            ptr1_pos++;
        }    
    }
    return ptr1->data;
}
//method 2
int middle2(Node* & head){
    Node* fast_ptr=head;
    Node* slow_ptr=head;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }
    return slow_ptr->data;
}

// given a linked list determine wether a cycle in it
// one method to use visited tag
// second using slow and fast ptr
bool detectCycle(Node* &head){
    if(!head){
        return false;
    }

    Node* fast_ptr=head;
    Node* slow_ptr=head;

    while(fast_ptr && fast_ptr->next){

        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;

        if (slow_ptr==fast_ptr){
            return true;
        }
    }
    return false;
}

// remove the cycle
/* floid'S algo says that the koi where both the ptr meets agar uss time ek ptr ko utho aur usko head par rakh do aur dono ko ek ek step se chalao toh they will meet at the begining of the cycle*/
void removeCycle(Node* &head){

    Node* fast_ptr=head;
    Node* slow_ptr=head;
    do
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    } while (slow_ptr!=fast_ptr);
    fast_ptr=head;
    while(fast_ptr->next!=slow_ptr->next){
        fast_ptr=fast_ptr->next;
        slow_ptr=slow_ptr->next;
    }
    slow_ptr->next=NULL;
}

//check wheather LL is palimdrome or not
//agey se toh LL ki dekh saktey hai but puchey se nhi! therefore we need to reverse the LL
// step 1 find middle ele
// break LL
// reverse the second half

bool check_palindrome(Node* &head){
    //find middle
    Node* ptr1=head;
    Node* ptr2=head;
    while(ptr2 && ptr2->next){
        ptr2=ptr2->next->next;
        ptr1=ptr1->next;
    }

    //reverse
    Node* pre = NULL;
    while(ptr1){
        Node*temp=ptr1->next;
        ptr1->next=pre;
        pre=ptr1;
        ptr1=temp;
    }
    //check
    Node* head1=head;
    Node* head2=pre;
    while(head2){
        if(head1->data!=head2->data) return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

//rotate the LL by k step
void rotateLL(Node* &head, int k){
    while(k){
        Node* temp=head;
        while(temp->next->next){
            temp=temp->next;
        }

        temp->next->next=head;
        head=temp->next;
        temp->next=NULL;
        k--;
    }
    //return head;
}
// method 2 traverse complete LL find length
//find k ki value les than n 
//kth node of the LL par jao break the LL from there
void rotateLL2(Node* &head, int k){
    //find length
    int n=1;
    // find tail
    Node* tail=head;
    while(tail->next){
        n++;
        tail=tail->next;
    }

    // finding value of k
    k-=n;
    cout<<k<<n-k<<endl;
    if(k==0) return;
    Node* temp=head;
    for(int i=1;i<n-k;i++) temp=temp->next;
    tail->next=head;
    head=temp->next;
    temp->next=NULL;
}

//given head of a LL group all odd indices together followed by thr nodes of even indices
void func(Node* &head){
    Node* temp1=head;
    Node* even=head->next;
    Node* temp2=even;
    while(temp2 && temp2->next){
        temp1->next= temp1->next->next;
        temp2->next=temp2->next->next;
        temp1= temp1->next;
        temp2=temp2->next;
    }
    temp1->next=even;
}

void func2(Node* &head){
    Node* temp1=head;
    Node* even=head->next;
    Node* temp2=even;
    while(temp2 && temp2->next){
        temp1->next= temp2->next;
        temp1= temp1->next;
        temp2->next=temp1->next;
        temp2=temp2->next;
    }
    temp1->next=even;
}


int main(){
    LinkedList L1;
    L1.InsertAt_tail(1);
    L1.InsertAt_tail(2);
    L1.InsertAt_tail(3);
    L1.InsertAt_tail(4);
    L1.InsertAt_tail(5);
    L1.InsertAt_tail(6);
    //L1.display(L1.head);
    //delete_alternative(L1.head);
    //display_reverse(L1.head);
    //L1.head=reverse2(L1.head);
    //L1.head=reverse_kAtTime(L1.head,2);
    //L1.display(L1.head);
    //delete_K_fromEnd(L1.head,3);
    //L1.display(L1.head);
    //cout<<middle2(L1.head);
    //cout<<check_palindrome(L1.head);
    //rotateLL(L1.head,8);
    //L1.display(L1.head);
    //rotateLL2(L1.head,8);
    func2(L1.head);
    L1.display(L1.head);

    LinkedList L2;
    L2.InsertAt_tail(5);
    L2.InsertAt_tail(6);
    // L2.head->next->next=L1.head->next->next->next;
    L2.InsertAt_tail(11);
    L2.InsertAt_tail(13);
    L2.InsertAt_tail(14);
    //L2.display(L2.head);
    //delete_duplicate(L2.head);
    //L2.display(L2.head);
    //cout<<check_equal(L1.head,L2.head)<<endl;
    //cout<<find_intersection(L1.head,L2.head);

    LinkedList L3;
    //L3.head=dummy_head(L1.head,L2.head);
    L3.InsertAt_tail(2);
    L3.InsertAt_tail(3);
    L3.InsertAt_tail(10);
    //L3.display(L3.head);
    vector<Node*> Vec={L1.head,L2.head,L3.head};
    //merge_multipleLL(Vec);
    //L3.display(Vec[0]);
    return 0;
}