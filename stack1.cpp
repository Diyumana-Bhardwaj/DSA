#include <iostream>
using namespace std;
#include <stack>

//ques1 copy stack to another stack in same order
// property of stack if we copy one stack to other the order is reversed
void copy(stack<int>& S1,stack<int>& S2){
    if (S1.empty()) return;
    int temp=S1.top();
    S1.pop();
    copy(S1,S2);
    S2.push(temp);
}
// TC O(n) SC O(n)

// method 2 taking extra space //method 1 me extra space recursion ke through hai
/*
oridinal    extra       destination stack
4            1              4
3            2              3
2            3              2
1 copy it    4 again copy   1
TC O(n)
SC O(n)
*/
void display(stack<int> cloned){
    while (!cloned.empty()) {
        std::cout << cloned.top() << std::endl;
        cloned.pop();
    }
}

// ques2 insert at bottom or any index
//method 1 ek stack se durse me shift kar do  aur beech me add kar dena reverse ho jaenge! phir vapas ussi stack me ek aur baar copy kardo add ho jaega 
void insertAtBottom(int val,stack<int>& S1){
    stack<int> st;
    while(!S1.empty()){
        st.push(S1.top());
        S1.pop();
    }
    S1.push(val);
    while(!st.empty()){
        S1.push(st.top());
        st.pop();
    }
}
// recursive approch
void insert(int val,stack<int>& S1){
    if (S1.empty()){
        S1.push(val);
        return;
    }
    int temp=S1.top();
    S1.pop();
    insert(val,S1);
    S1.push(temp);
}
// at particular index
void insertion(int val,int index,stack<int>& S1){
    if(index>S1.size()||(S1.size()-index)==0){
        S1.push(val);
        return;
    }
    int temp=S1.top();
    S1.pop();
    insertion(val,index,S1);
    S1.push(temp);
}
// remove from bottom / any index
void deletion(int index,stack<int>& S1){
    if((S1.size()-index)==1){
        S1.pop();
        return;
    }
    int temp=S1.top();
    S1.pop();
    deletion(index,S1);
    S1.push(temp);
}
// reverse the stack 
/* 
mehtod1
oridinal    extra        extra 2    original
4            1              4           1
3            2              3           2
2            3              2           3
1 copy it    4 again copy   1           4 reversed
*/
void reverse(stack<int>& S1){
    if (S1.empty()) return;
    int temp=S1.top();
    S1.pop();
    reverse(S1);
    insertAtBottom(temp,S1); // internally ek aur stack baan jaega
}

// balanced bracket sequence
//"(([)])" or "({[]}())"
// The algorithm iterates through the input string, pushing opening brackets onto the stack and popping them when a matching closing bracket is encountered. If a closing bracket doesn’t match the top of the stack or if the stack is empty when a closing bracket is encountered, the function returns False
#include <map>
bool match_pairs(char a,char b){
    if(a=='(' && b==')') return true;
    if(a=='[' && b==']') return true;
    if(a=='{' && b=='}') return true;
    if(a=='<' && b=='>') return true;
    return false;
}
bool balanced(const string &s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['||c=='{'||c=='<')
        st.push(c);
        else if(c==')'||c==']'||c=='}'||c=='>') {
            if(st.empty()) return false;
            char top=st.top();
            st.pop();
            if(!match_pairs(top,c)) return false;
        }
    }
    return st.empty(); //for case "({[]}()"
}

//next greater element
// [4,3, 9,1,6, 8, 2]  input
// [9,9,-1,6,8,-1,-1]  output
// wait  is equal to stack and also graph from pics
#include <vector>
vector<int> NGE(vector<int> arr){
    int size=arr.size();
    stack<int> st;
    vector<int> ans(size,-1);
    st.push(0);
    for(int i=1;i<size;i++){
        if(st.empty() || arr[i]<arr[st.top()] ) st.push(i);
        else if(arr[i]>arr[st.top()]){
            while(!st.empty() && arr[i]>arr[st.top()]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

// next smaller element similarly previous smaller element
vector<int> NSE(vector<int> arr){
    int size=arr.size();
    stack<int> st;
    vector<int> ans(size,-1);
    st.push(0);
    for(int i=1;i<size;i++){
        if(st.empty() || arr[i]>arr[st.top()] ) st.push(i);
        else if(arr[i]<arr[st.top()]){
            while(!st.empty() && arr[i]<arr[st.top()]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

//stock ques! find privious greater element
vector<int> NSE(vector<int> arr){
    int size=arr.size();
    stack<int> st;
    vector<int> ans(size,1);
}
int main(){
    stack<int> st;
    stack<int> st2;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    //display(st);
    //copy(st,st2);
    //insertion(12,0,st);
    //reverse(st);
    //display(st);
    //cout<<balanced(")()");
    vector<int> v={4,6,3,1,0,9,5,6,7,3,2};
    vector<int> ans= NSE(v);
    for(int i= 0;i<11;i++) cout<<ans[i]<<" ";
}