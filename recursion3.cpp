#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//given a 2*n board and the  tile of size 2*1 , count no of ways to tile the given board
/*
copy*/ //fibonacii series
int ways(int n){
    //base case
    if(n==1) return 1;
    if(n==0) return 0;
    ways(n-1)+ways(n-2);
}


//friends pairing problem
//find the no of ways in which n friends can be paired or remain single
int pairing(int n){
    if(n==0 || n==1 ||n==2) return n;
    return pairing(n-1) + pairing(n-2)*(n-1); //nth banda can be paired with n-1 log therefore n-1 ways to pair
}

//knapsack problem
// sack ka weight given hai aur kuch items unki value aur 
//unka weight given hai 