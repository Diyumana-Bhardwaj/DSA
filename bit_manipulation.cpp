#include <iostream>
using namespace std;
/*get bit n=0101 =5
          3210
suppose we need to get bit at position ,i=02*/

// to get the bit first we need to form a number in binary where there is only 1 at the position we neeed to fing
/*1<<i=0100 use of left shift operator
now will and the number given and number form why and kyu uss position ke alawa baaki sab zero 
aur agar voh postion bhi zero therefore bit was 0 else bit was 1
0100 & 0101 =0100*/

int getbit(int n,int pos){
    return((n&(1<<pos))!=0);
}
// int main(){
//     cout<<getbit(5,2);
//     return 0;
// }

//set bit
/*n=0101
suppose we need to set bit at position i=1
1<<i=0010 now bitwis or operator
0101 | 0010= 0111 ans*/
int setbit(int n,int pos){
    return (n|(1<<pos));
}
// int main(){
//     cout<<setbit(5,1);
//     return 0;
// }

// clear bit
/*n=0101
suppose we need to clear bit at postion 2
1<<i=0100
~0100 = 1011
bitwis and operator 0001 ans
*/

//update bit
/*
n=0101
suppose we need ro update a bit at position i=1,1
1<<i=0010
step 1 clear bit of that position  it will become 0
if update 1 se karni hai toh normally btwise or
*/

// write a program to check if the given number is power of two
/*
32 16 8 4 2 1
dekho agar right most bit agar 0 hogi toh power 2 ki hogi*/
//problem yeah multiple toh bata dekhi power nhi bataegi
bool check(int n){
    return ((n&1)? 0:1);
}
int main(){
    cout<<check(6);
}

// now for power lets notice one thing
/*all the power of 2 has only 1 bit like 0100 010 010000 
and n-1 is just flip of the bits after rightmost set / 1 bit
n=6 0110 or 110 right most 1 is at postiom 1
n=5  101    101
similarly 8 = 1000
          7=  0111 right most 1 se flip

6&5=0100
8&7=0000 yeahi hoga for every power of 2
*/

// count no of ones in binary representaion
/* (n&n-1) has same bits as n except the right most bit of 1
repeat this process and count the no of times u did to get a one */

// all possible subset of a set
/*{a,b,c}
{}      0 0 0   0
{c}     0 0 1   1
{b}     0 1 0   2   i will run from 0 to (1<<n) means 2^n
{b,c}   0 1 1   3   j will check if the bit is 0 / 1 so j will iterate from 0 to n
{a}     1 0 0   4   for that 1<<j set 1 to jth place and use bitwise and
{a,c}   1 0 1   5
{a,b}   1 1 0   6
{a,b,c} 1 1 1   7   0->(2^n-1)*/

void findSubsets(int nums[], int n)
{
    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add the jth element to the subset
                cout << nums[j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    int arr[] = { 1, 2, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    findSubsets(arr, n);
}

//to fing unique number in an array
/* using XOR
A   B   A^B
0   0   0
0   1   1
1   0   1
1   1   0
ek number ka ussi ke sath XOR is 0.    
*/
int unique(int arr[],int n){
    int xorsum=0;
    for(int i= 0;i<n;i++)
    xorsum^=arr[i];
    return xorsum;
}
int main(){
    int arr[]={1,2,3,4,3,2,1};
    cout<<unique(arr,7);
}
/*
Iteration 1: xorsum = 0 ^ 1 = 1
Iteration 2: xorsum = 1 ^ 2 = 3
Iteration 3: xorsum = 3 ^ 3 = 0
Iteration 4: xorsum = 0 ^ 4 = 4
Iteration 5: xorsum = 4 ^ 3 = 7
Iteration 6: xorsum = 7 ^ 2 = 5
Iteration 7: xorsum = 5 ^ 1 = 4 screen short*/

// find two unique number in an array
/*2,4,6,7,5,6,2
agar in sabka XOR karey ek me bacheyga 
7^5 or 
0111
0101
_____
0010 ab ja par bhi zero hai we know / dono me 0/1
jaha par bhi 1 hai ek me 0 and ek me 1*/

//Unique element in an array where all elements occur K times except one 
#include <math.h>
int unique(int arr[],int n,int k){
    int num=0;
    for(int i=0;i<32;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=(abs(arr[j]) & (1 << i)) != 0 ? 1 : 0;
        }
        sum%=k;
        num+=pow(2,i)*sum;
    }
    return num;
}

int main(){
    int arr[]={1,2,3,1,2,3,3,1,2,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<unique(arr,size,3);
}

//sieve of eratosthenes
/*helps to give the prime numbers upto n
algorithm from geeks for geeks*/
#include <vector>
void SieveOfEratosthenes(int n){
    vector<bool> prime(n+1,true);
    for(int i=2;i<=n;i++){
        if(prime[i]==true){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) cout<<i<<" ";
    }
}

int main(){
    SieveOfEratosthenes(30);
}

//inclusion exclusion
/*
suppose n1 student took bio
n2 took maths
n3 took both 
so total will be n1+n2-n3 
this is in/ex*/

//how many number between 1 to 1000 are divisible by 5 / 7
/*n1=number division by 5
n2=number division by 7
n3=number division by both 5 7
n1+n2-n3*/

//gcd or hcf

