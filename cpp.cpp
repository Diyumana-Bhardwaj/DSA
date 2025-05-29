/*#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<char(j+64);
        for(int j =i-1;j>=1;j--)
        cout<<char(j+64);
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<char(j+64);
        for(int j =i-1;j>=1;j--)
        cout<<char(j+64);
        cout<<endl;
    }
}*/

/*#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<char(j+64);
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<char(j+64);
        cout<<endl;
    }
}*/

/*#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=n;j++)
        cout<<char(j+64);
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=n;j++)
        cout<<char(j+64);
        cout<<endl;
    }
}*/

/*#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=(2*i-1);j++)
        cout<<char(j+64);
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=(2*i-1);j++)
        cout<<char(j+64);
        cout<<endl;
    }
}*/

/*#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=(2*i-1);j++)
        cout<<j-1;
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++)
        cout<<" ";
        for(int j=1;j<=(2*i-1);j++)
        cout<<j-1;
        cout<<endl;
    }
}*/

#include <iostream>
using namespace std;
/*int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==(n+1)/2){
            for(int j=1;j<=n;j++)
            cout<<"*";
        }
        else{
            for(int j=1;j<=n;j++)
            if(j==(n+1)/2)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}*/

/*int main(){
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            if((j<=i)||(j>(2*n-i)))
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i =n-1;i>=1;i--){
        for(int j=1;j<=2*n;j++){
            if((j<=i)||(j>(2*n-i)))
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}*/

/*int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=21;j++){
            int m=j+i,n=j-i;
            if(m==6||m==14||m==22||n==4||n==12)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}*/

//enter to sorted array merge then into an sorted array
/*int main(){
    int n,m,temp;
    cin>>n;
    cin>>m;
    int arr1[n],arr2[m],arr12[m+n];
    cout<<"enter array 1\n";
    for(int i=0;i<n;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr1[i];
    }
    cout<<"enter array 2\n";
    for(int i=0;i<m;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr2[i];
    }
    //merge
    for(int i=0;i<n+m;i++){
        if(i<n)
        arr12[i]=arr1[i];
        else
        arr12[i]=arr2[i-n];
    }

    //sorting
    for(int i=0;i<n+m;i++){
        for(int j=i+1;j<n+m;j++){
            if (arr12[i]>arr12[j]){
            temp=arr12[i];
            arr12[i]=arr12[j];
            arr12[j]=temp;
            }   
        }
    }

    //printing
    for(int i=0;i<n+m;i++)
    cout<<arr12[i]<<" ";
}*/

//target sum of duplet
/*int main(){
    int n,x,count=0;
    cin>>n;
    cin>>x;
    int arr1[n];
    cout<<"enter array 1\n";
    for(int i=0;i<n;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr1[i]+arr1[j]==x){
                count=1;
            }
        }
    }
    if (count==1)
    cout<<"Yes";
    else
    cout<<"No";
}*/

//*target sum of triplet
/*int main(){
    int arr[] = {3,1,2,4,0,6};
    int size=6,targetsum=6,count=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=i+2;k<size;k++){
                if(arr[i]+arr[j]+arr[k]==targetsum)
                count++;
            }
        }
    }
    cout<<count;
}*/

//******array manipulation ques-find unique no in the given array where all the elements are being repeated twice with one value being unique
// way to find the pair and replace all the pairs with either 0/-1 and print thr no other than it
/*int main(){
    int arr[]={2,3,1,3,2,4,1};
    for(int i=0;i<7;i++){
        for(int j=i+1;j<=7;j++){
            if(arr[i]==arr[j])
            arr[i]=arr[j]=-1;
        }
    }
    for(int i=0;i<7;i++){
        if(arr[i]>0)
        cout<<arr[i];
    }
}*/
//method 2
/*int main(){
    int arr[]={2,3,1,3,2,4,1};
    for(int i=0;i<7;i++){
        int count=0;
        for(int j=0;j<7;j++){
            if(arr[i]==arr[j])
            count++;
        }
        if(count==1)
        cout<<arr[i];
    }
}*/

//*****second largest element in array(sorting and largest element ques are weak)
//sort array
//make lagest value to 0 /-1 then find lagest
//find lagest then find second

/*int max(int array[],int size){
    int largest=INT_MIN;
    for(int i=0;i<size;i++){
        if(array[i]>largest)
        largest=array[i];
    }
    return largest;
}
int second_max(int arr[],int size,int max){
    int second_largest=INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>second_largest && arr[i]<max)
        second_largest=arr[i];
    }
    return second_largest;
}
int main(){
    int arr[]={1,257,91,34,200,67,92};
    int n=sizeof(arr)/sizeof(arr[0]);
    int second;
    second=second_max(arr,n,max(arr,n));
    cout<<second;
}*/

//rotateing an array by k steps
//we can use directly reverse operations of the vectors
/*int main(){
    int array[]={1,2,3,4,5},k;
    int size=sizeof(array)/sizeof(array[0]);
    cin>>k;
    if (k>size)
    k-=size;
    for(int i=0;i<k;i++){
        int temp=array[size-1];
        for(int i=size-1;i>0;i--){
            array[i]=array[i-1];
        }
        array[0]=temp;
    }
    for(int i=0;i<size;i++)
    cout<<array[i]<<" ";
}*/

//q queries ,check if thr given number is present or not
// one way to traverse the complete array q times
// second way

//sort an array only zeros and one
/*#include <vector>
int main(){
    vector<int> v;
    int n,count;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;cin>>ele;
        v.push_back(ele);
    }
    for(int i=0;i<n;i++){
        if (v[i]==0)
        count++;
    }
    for(int i=0;i<n;i++){
        if (i<=count)
        v[i]=0;
        else
        v[i]=1;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}*/

//method 2 (2 pointer method)
/*int main(){
    int array[]={1,0,1,0,0,0,1,0,1,0,1};
    int size=sizeof(array)/sizeof(array[0]);
    int p_start=0,p_end=size-1;
    while(p_start<p_end){
        if(array[p_start]==1){
            int temp=array[p_start];
            array[p_start]=array[p_end];
            array[p_end]=temp;
            p_end--;
        }
        else{
            p_start++;
        }
    }
    for(int i=0;i<size;i++){
        cout<<array[i];
    }
}*/

//moving all the even integer athe beigning and all the odd at the end
/*int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int ptr1=0,ptr2=size-1;
    while(ptr1<ptr2){
        if(arr[ptr1]%2!=0){
            int temp=arr[ptr1];
            arr[ptr1]=arr[ptr2];
            arr[ptr2]=temp;
            ptr2--;
        }
        else
        ptr1++;
    }
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}*/

// ****given an array in inc form return an array of sqaures in inc form
/*int main(){
    int arr[]={-2,-1,0,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int ptr1=0,ptr2=size-1;
    while(ptr1<=ptr2){
        if((abs(arr[ptr1])>abs(arr[ptr2]))){
            int temp=arr[ptr1]*arr[ptr1];
            arr[ptr1]=arr[ptr2]*arr[ptr2];
            arr[ptr2]=temp;
            ptr2--;
            ptr1++;
        }
        else if ((abs(arr[ptr1])<abs(arr[ptr2])) && (arr[ptr1]<=0))
        {
            int temp=arr[ptr1];
            arr[ptr1]=arr[ptr2]*arr[ptr2];
            arr[ptr2]=temp;
            ptr1++;
        }
        
        else{
            arr[ptr1]*=arr[ptr1];
            ptr1++;
        }
    }
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}*/

//return prefix sum/running sum in the same array without creating an new arr
/*int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr[i];
    }
    for(int i = n-1;i>=0;i--){
        int sum=0;
        for(int j=0;j<=i;j++){
            sum+=arr[j];
        }
        arr[i]=sum;
    }
    for(int i = 0;i<n;i++)
    cout<<arr[i]<<" ";
}*/

//check that the prefix sum of a part of the array is equal the suffix sum of the array
/*int main(){
    int n,count,index;
    cin>>n;
    int arr[n],ptr1=1,ptr2=n-2;
    for(int i = 0;i<n;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr[i];
    }
    int sum1=arr[0],sum2=arr[n-1];
    while(ptr1!=n){
        if(sum1>sum2){
            sum2+=arr[ptr2];
            ptr2--;
        }
        else
        sum1+=arr[ptr1];
        ptr1++;

        if(sum1==sum2){
            count++;index=ptr1-1;
            break;
        }
    }
    if(count==1){
        cout<<"Yes"<<endl<<"sub array 1= ";
        for(int i=0;i<index;i++)
        cout<<arr[i]<<' ';
        cout<<"\nsub array 2= ";
        for(int i=index;i<n;i++)
        cout<<arr[i]<<' ';
    }
    else
    cout<<"no";
}*/

//method2
/*int main(){
    int n,sum=0,count=0,index;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i = 0;i<n;i++){
        int prefix = 0;
        for(int j=0;j<=i;j++){
            prefix+=arr[j];
        }
        if (prefix==sum/2 && i!=n-1){
            count++;
            index=i;
            break;
        }
    }
    if(count==1){
        cout<<"Yes"<<endl<<"sub array 1= ";
        for(int i=0;i<=index;i++)
        cout<<arr[i]<<' ';
        cout<<"\nsub array 2= ";
        for(int i=index+1;i<n;i++)
        cout<<arr[i]<<' ';
    }
    else
    cout<<"no";
}*/

//given array of size n,answer q queries where you need to print the sum of values in given rande lto r inculding both
/*int main(){
    int n,q;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr[i];
    }
    cout<<"enter the no of query";
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r,sum=0;
        cin>>l>>r;
        for(int i=l;i<=r;i++){
            sum+=arr[i];
        }
        cout<<"sum="<<sum;
    }
}*/

//method 2 can make a array of n+1 and make ele at index 0 be zero
/*int main(){
    int n,q;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cout<<"arr["<<i<<"]=";
        cin>>arr[i];
    }
    cout<<"enter the no of query";
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r,sum_l=0,sum_r=0;
        cin>>l>>r;
        for(int i=0;i<=r;i++){
            sum_r+=arr[i];
        }
        for(int i=0;i<l;i++){
            sum_l+=arr[i];
        }
        cout<<"sum="<<sum_r-sum_l;
    }
}*/

// 2d array
//datatype array[row][col] 

 //matrix multiplication
 /*# define N 50
 int main(){
     int m,n,p;
    int a[N][N],b[N][N],c[N][N];
    cout<<"enter rows and column for matrix 1\t";
    cin>>m>>n;
    cout<<"enter matrix 1:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }
    }

    cout<<"enter column for matrix 2\t";
    cin>>p;
    cout<<"enter matrix 1:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout<<"b["<<i<<"]["<<j<<"]=";
            cin>>b[i][j];
        }
    }
    cout<<"matrix 1:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }

    cout<<"matrix 2:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
    //multiplication
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            int sum=0;
            for(int k=0;k<n;k++)
            sum+=(a[i][k]*b[k][j]);
            c[i][j]=sum;
        }
        

    }
    cout<<"matrix multiplication:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
 }*/

// 2d vector - vector of vector data type
/*2d array-array of arrays
syntax= vector<vector<datatype>> vector name;
 vector<int> v1={1,2,3}
vector<int> v2={4,5}
vector<int> v3={6,7}
vector<vector<int>> V={v1,v2,v3}
or V=
{{1,2,3}
{4,5}
{6,7}}
n*m vector intialize
vector<vector<int>> V(n,Vector<int> (m))
for null /1s vector of 3*4
vector<vector<int>> V(3,Vector<int> (4,0))
*/

// pascals triangle
/*
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1 for n=5 ques=nth row only,upto nth row , specific triangle

 visualize 
                rows    col     ele
1               1       1       0C0
1 1             2       2       1C0 1C1
1 2 1           3       3       2C0 2C1 2C2
1 3 3 1         4       4       3C0 3C1 3C2 3C3
1 4 6 4 1       5       5       4C0 4C1 4C2 4C3 4C4
                1->n    1->row   0->N-1
                                nCr=n!/(n-r)!r!
*/
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             int term=1;
//             for(int k=0;k<i-j;k++){
//                 term*=(i-k);
//                 term/=(k+1);
//             }
//             cout<<term<<" ";
//         }
//         cout<<endl;
//     }
// }

// method 2 using sum , nth ele is sum  of above row just above ele and left
//a[i][j]=a[i-1][j]+a[i-1][j-1] and boundary element is one
/*#include <vector>
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(50,vector<int>(50,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j!=0 && j!=i){
                vec[i][j]=vec[i-1][j]+vec[i-1][j-1];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}*/

/*int main(){
    int row,col,count=0,index=0;
    cin>>row>>col;
    bool arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<row;i++){
        int count_ones=0;
        for(int j=0;j<col;j++){
            if(arr[i][j]==1)
            count_ones++;
        }
        if (count_ones>count){
            count=count_ones;
            index=i;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Row no= "<<index+1;
}*/

// alternative 
//**sort the array and check the left most index where the frst one occur the least is the index the more no of ones
/*int LeftMostOneRow(vector<vector<int>> &V){
    int LeftMostOne = -1;
    int maxOnesRow = -1;

    // finding leftmost one in 0th row
    for(int j=0;j<V[0].size();j++)
}*/

//given a square matrix , turn it by 90 deg clockwise without using extra space
//input=[[1,2,3],[4,5,6],[7,8,9]] fisrt row will become last col
//output=[[7,4,1],[8,5,2],[9,6,3]] transpose  without using extra sapce ka ques
/*
original 90     transpose
1 2 3   7 4 1   1 4 7
4 5 6   8 5 2   2 5 8       aur transpose ke liye i aur j walo ko swap kardo  
7 8 9   9 6 3   3 6 9       tranpose nikal ke first aur last col ko swap kardo
*/
#include <vector>
#include <bits/stdc++.h>
/*int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<int>> V(50,vector<int>(50));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>V[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    //transpose
    for (int i = 0; i < row; i++){
        for (int j = i + 1; j < col; j++) 
            swap(V[i][j], V[j][i]);
    }
    //90 deg
    for(int i=0;i<col;i++){
        swap(V[i][0],V[i][row-1]);
    }
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
}*/

//v.v.v.v.imp
// return all elements of ele of n*m in spring form
/*
        left    right
top->   1   2   3          top will be increement as the horizontal line complete as move down
        4   5   6          bottom will decrease and come upwards
 bottom 7   8   9         left will more towards right and visa verra until all the four condition is true
 if satement in while loop is for the condition when non square matrix
 if no if statement added 
 0 1 2 3
 4 5 6 7
 8 9 10 11 output 0 1 2 3 7 11 10 9 8 4 5 6 5
*/
/*int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<int>> V(50,vector<int>(50));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>V[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    int top=0,left=0,bottom=row-1,right=col-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++)
        cout<<V[top][i]<<" ";
        top++;
        for(int j=top;j<=bottom;j++)
        cout<<V[j][right]<<" ";
        right--;
        if (top<bottom){
            for(int k=right;k>=left;k--)
            cout<<V[bottom][k]<<" ";
            bottom--;
        }
        if(left<right){
            for(int i=bottom;i>=top;i--)
            cout<<V[i][left]<<" ";
            left++;
        }
    }
}*/

//taking input of array in spiral
/*int main(){
    int n;
    cin>>n;
    int top=0,left=0,bottom=n-1,right=n-1;
    vector<vector<int>> V(n,vector<int>(n));
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<"V["<<top<<"]["<<i<<"]=";
            cin>>V[top][i];
        }
        top++;
        for(int j=top;j<=bottom;j++){
            cout<<"V["<<j<<"]["<<right<<"]=";
            cin>>V[j][right];
        }
        right--;
        if (top<bottom){
            for(int k=right;k>=left;k--){
                cout<<"V["<<bottom<<"]["<<k<<"]=";
                cin>>V[bottom][k];
            }
            bottom--;
        }
        if(left<right){
            for(int i=bottom;i>=top;i--){
                cout<<"V["<<i<<"]["<<left<<"]=";
                cin>>V[i][left];
            }
            left++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
}*/

//given a array of n*m and two cordinate (l1,r1) and (l2,r2) return sume of the rectangle formed
//using spiral
/*int main(){    
    int row,col,l1,l2,r1,r2,sum=0;
    cin>>row>>col;
    vector<vector<int>> V(50,vector<int>(50));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>V[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"enter value of l1 and r1;";
    cin>>l1>>r1;
    cout<<"enter value of l2 and r2;";
    cin>>l2>>r2;
    int top=l1,left=r1,bottom=l2,right=r2;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++)
        sum+=V[top][i];
        top++;
        for(int i=top;i<=bottom;i++)
        sum+=V[i][right];
        right--;
        if(top<bottom){
            for(int i=right;i<=left;i++)
            sum+=V[bottom][i];
            bottom--;
        }
        if(left<right){
            for(int i=bottom;i<=top;i++)
            sum+=V[left][i];
            left++;
        }
    }
    cout<<sum;

}*/

//method1
/*int main(){    
    int row,col,l1,l2,r1,r2,sum=0;
    cin>>row>>col;
    vector<vector<int>> V(50,vector<int>(50));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>V[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"enter value of l1 and r1;";
    cin>>l1>>r1;
    cout<<"enter value of l2 and r2;";
    cin>>l2>>r2;
    for(int i=l1;i<=l2;i++){
        for(int j=r1;j<=r2;j++)
        sum+=V[i][j];
    }
    cout<<sum;
}*/

//method 2 using prefix sum array
/*pre calculate prefix sum of all 
eg 1 2 3 4 5 --- 1 3 6 10 5
where arr[l]= arr[0] + ------- +arr[l]
and arr[r]= arr[0]+ -----+arr[l]+-----+ arr[r]
sum of eleem to r to l = arr[r]-arr[l-1]
1  2 3  4      1  3  6  10
5 |6 7| 8     *5 11 *18 26          6+7= 18-5
9 10 11 12     9 19  30 42                r-(l-1)
*/
/*int main(){
    int row,col,l1,l2,r1,r2,sum=0;
    cin>>row>>col;
    vector<vector<int>> V(50,vector<int>(50));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>V[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"enter value of l1 and r1;";
    cin>>l1>>r1;
    cout<<"enter value of l2 and r2;";
    cin>>l2>>r2;

    // prefix array
    for(int i=0;i<row;i++){
        for(int j=1;j<col;j++)
        V[i][j]+=V[i][j-1];
    }
    for(int i=l1;i<=l2;i++)
    sum+=V[i][r2]-V[i][r1-1];
    cout<<sum;
}*/

//method 3 prefix sum over both rows and column
/*
1 2  3  4     1 3  6  10      1  3  6  10
5 6  7  8     5 11 18 26      6  14 24 36
9 10 11 12    9 19 30 42      15 33 54 78
6+7+10+11 =                   54-15-6
l1,r1-> l2,r2                 arr[l2,r2]-arr[0,r1]-arr[l1,0]
*/
/*int main(){
    int row,col,l1,l2,r1,r2,sum=0;
    cin>>row>>col;
    vector<vector<int>> V(50,vector<int>(50));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>V[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"enter value of l1 and r1;";
    cin>>l1>>r1;
    cout<<"enter value of l2 and r2;";
    cin>>l2>>r2;

    // prefix array row
    for(int i=0;i<row;i++){
        for(int j=1;j<col;j++)
        V[i][j]+=V[i][j-1];
    }

    //prefix sum array column
    for(int i=0;i<col;i++){
        for(int j=1;j<row;j++)
        V[j][i]+=V[j-1][i];
    }
    sum+=(V[l2][r2]-(V[l1-1][r2]+V[l2][r1-1])+V[l1-1][r1-1]);
    cout<<sum;
}*/
    
