//TIME AND SPACE COMPLEXITY
//INTRO
/*
taking an example
ques-given a number x and y where(1<=x<=10^5)and (1<=y<=10^5) calc sumof all numbers in the range [x,y]
*/
// method 1
int main(){
    int x,y,sum;
    cin>>x>>y;
    for(int i=x;i<=y;i++)
    sum+=i;
    return sum;
}
// this is one method is method is very must coreect but if the value of x=1 and y=10^4 the for loop has to iterate almost 10^4 times 
//which is a big slow process so we can optimize using ap
/*
we know the series must be like this 1,2,3,4,5,6
its nothing but an ap
sum of n terms of an ap = n/2*(2*a+(n-1)*d)=n/2*(a+l)
n=y-x+1
therefore the formula is= (y+x-1)/2*(x+y)
*/
int main(){
    int x,y,sum;
    cin>>x>>y;
    sum=(y+x-1)*(x+y)/2;
    return sum;
}
// we cant calculate algorithm productivity through exectuive time bcoz it changes everytime te code runs bcoz in the background several other processes are runing due which the execution by sys might delay
// therefore experimantal analysis are not considered
// we talk in terms of no of operations/no of instruction
/*
which says is a algorithm takes 10^5 instructions/operations
and other  takes 10 instructions then ovio 10 will operate faster by the sys
the first one was 1. experimental analysis
2. asymptotic analysis
*/