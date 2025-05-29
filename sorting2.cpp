#include <iostream>
#include <string.h>
using namespace std;
//insertion sort
void sorting(int arr[], int n){
    int key;
    int i=0;
    while(i<n){
        if(arr[i]!=0) i++;
        else{
            key=arr[i];
            int j=i+1;
            while(j<n){
                arr[j-1]=arr[j];
                j++;
            }
            arr[j-1]=key;
            n--;
        }
        
    }
}
// bubble sort
void swapZeros(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        int j=0;
        bool flag=false;
        while(j!=i){
            if(arr[j]==0 && arr[j+1]!=0){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
            j++;
        }
        if(!flag) break;
    }
}
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//ques 2
// sort array of string in lexicographical order
 void dictionary(char arr[][60],int n){
    bool flag;
    for(int i=0;i<n-1;i++){
        flag=false;
        for(int j=0;j<n-i-1;j++){
            if (strcmp(arr[j],arr[j+1])>0){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
    }
 }
 // if no swap func
/*
void dictionary(char arr[][60],int n){
    bool flag;
    for(int i=0;i<n-1;i++){
        flag=false;
        for(int j=0;j<n-i-1;j++){
            int length = (strlen(arr[j])>strlen(arr[j+1]))?strlen(arr[j]):strlen(arr[j+1]);
            for(int k=0;k<length;k++){
                if(arr[j][k]>arr[j+1][k]){
                    swap(arr[j],arr[j+1]);
                    flag=true;
                    break;
                }
                if(arr[j][k]<arr[j+1][k]) break;
            }
        }
        if(!flag) break;
    }
 }*/

//ques 3 
//write a program to find kth smallest element using quick sort
//k-1 index par joh element hoga in the sorted array
// first sort then find O(nlogn)
// of TC O(n)
int partition(int arr[],int low,int high){
int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
int quickSort(int arr[],int low,int high ,int key){
    int pi=partition(arr,low ,high);
    if(pi==(key-1)) return arr[pi];
    if(pi<(key-1)) quickSort(arr,pi+1,high,key);
    else quickSort(arr,low,pi-1,key);
}

//ques4
void swap_0_1_2(int arr[],int N){
    int ptr=0,head=0,tail=N-1;
    while(ptr!=tail){
        if(arr[ptr]==2){
            //insertion ele at last using insertion method
            int temp=arr[ptr];
            int temp_ptr=ptr;
            while(temp_ptr!=N-1){
                arr[temp_ptr]=arr[temp_ptr+1];
                temp_ptr++;
            }
            arr[N-1]=temp;
            tail--;
        }
        if(arr[ptr]==0){
            if(head==ptr) ptr++;
            else{
                int temp=arr[ptr];
                int temp_ptr=ptr;
                while(temp_ptr!=head){
                    arr[temp_ptr]=arr[temp_ptr-1];
                    temp_ptr--;
                }
                arr[head]=temp;
            }
            head++;
        }
        if(arr[ptr]==1) ptr++;
    }
}

//ques 5
void positive_negitive(int arr[],int N){
    int ptr=0,n_inx=0;
    while(ptr!=N){
        if(arr[ptr]<0){
            swap(arr[ptr],arr[n_inx]);
            n_inx++;
        }
        ptr++;
    }
}
//by maintaining relavitve order
void segregate_alt(int arr[],int N){
    int ptr=0,n_inx=0;
    while(ptr!=N){
        if (arr[ptr]<0){
            int temp_ptr=ptr;
            int temp=arr[ptr];
            while(temp_ptr!=n_inx){
                arr[temp_ptr]=arr[temp_ptr-1];
                temp_ptr--;
            }
            arr[n_inx]=temp;
            n_inx++;
        }
        ptr++;
    }
}

int main(){
    int arr[]={3,4,2,1,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    // sorting(arr,n);
    // print_array(arr,n);
    char dict[][60]={"pomelo","pomegranate","pear","peach","plum","pineapple","papaya"};
    int N=sizeof(dict)/sizeof(dict[0]);
    // dictionary(dict,N);
    // for(int i=0;i<N;i++)
    // cout<<dict[i]<<" ";
    //cout<<quickSort(arr,0,n-1,5);
    int array[]={1,0,0,2,1,2,0,1,2,2,1,0,2,0,1};
    int na=sizeof(array)/sizeof(array[0]);
    // swap_0_1_2(array,na);
    // print_array(array,na);
    int array2[]={-3,9,-4,-1,8,3,-7,6,-5,1};
    int na2=sizeof(array2)/sizeof(array2[0]);
    segregate_alt(array2,na2);
    print_array(array2,na2);
    return 0;
}