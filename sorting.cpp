// BUBLE SORT
#include <iostream>
# include<algorithm>
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int n){
    bool flag;
    for(int i=0;i<n-1;i++){
        flag=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]> arr[j+1]) swap(arr[j],arr[j+1]);
            flag=true;
        }
        if(flag==false) break;
    }
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={20,40,10,30,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    print_array(arr,n);
    return 0;
}

//merge
void merge(int arr[], int left, int  mid,int right){
    int subArr1=mid - left + 1;
    int subArr2=right - mid;
    auto *a= new int[subArr1],
    *b= new int[subArr2];

    for (int i = 0; i < right+1; i++){
        if (i<subArr1) a[i] = arr[left + i];
        else b[i-subArr1] = arr[left + i];
    }

    int ptr1 = 0, ptr2 = 0;

    for(int i=left;i<right+1;i++){
        if (ptr1< subArr1&& ptr2 < subArr2) {
            if (a[ptr1]<= b[ptr2]) {
                arr[i]= a[ptr1];
                ptr1++;
            }
            else {
                arr[i]= b[ptr2];
                ptr2++;
            }
        }

        else if (ptr1< subArr1 && ptr2==subArr2) {
            arr[i]= a[ptr1];
            ptr1++;
        }

        else if (ptr2 < subArr2 && ptr1==subArr1) {
            arr[i]= b[ptr2];
            ptr2++;
        }
    }
    
    delete[] a;
    delete[] b;
}

void mergeSort(int arr[], int begin, int end)
{
    if (begin >= end)
        return;

    int mid = (begin +end) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}


int main()
{
    int arr[] = {9,2,6,4,7,3,8,1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);
    print_array(arr, arr_size);
    return 0;
}

//merge using while loop
void merge(int arr[], int left, int  mid,int right){
    int subArr1=mid - left + 1;
    int subArr2=right - mid;
    auto *a= new int[subArr1],
    *b= new int[subArr2];

    for (int i = 0; i < right+1; i++){
        if (i<subArr1) a[i] = arr[left + i];
        else b[i-subArr1] = arr[left + i];
    }

    int ptr1 = 0, ptr2 = 0;
    int indexOfMergedArray = left;

    while (ptr1< subArr1&& ptr2 < subArr2) {
        if (a[ptr1]<= b[ptr2]) {
            arr[indexOfMergedArray]= a[ptr1];
            ptr1++;
        }
        else {
            arr[indexOfMergedArray]= b[ptr2];
            ptr2++;
        }
        indexOfMergedArray++;
    }

    while (ptr1< subArr1) {
        arr[indexOfMergedArray]= a[ptr1];
        ptr1++;
        indexOfMergedArray++;
    }

    while (ptr2 < subArr2) {
        arr[indexOfMergedArray]= b[ptr2];
        ptr2++;
        indexOfMergedArray++;
    }
    delete[] a;
    delete[] b;
}

void mergeSort(int arr[], int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end -begin)/ 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6,};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
    return 0;
}

//binary search
int binary_search(int arr[],int low,int high, int target){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)
        return mid;

        if(arr[mid]<target)
        low= mid+1;

        if(arr[mid]>target)
        high = mid-1;

    }
    return -1;
}

int binarySearch(int arr[],int low,int high, int target){
    int mid = (low+high)/2;
    //base cae
    if(low>high) return -1;
    if(arr[mid]==target) return mid;

    //recursion
    if(arr[mid]<target)
    return binarySearch(arr,mid+1,high,target);

    if(arr[mid]>target)
    return binarySearch(arr,low,mid-1,target);
}
int main(){
    int arr[]={1,3,5,6,8,9,11,14,17,19};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ele=binarySearch(arr,0,n-1,15);
    cout<<"index value: "<<ele;
    return 0;
}