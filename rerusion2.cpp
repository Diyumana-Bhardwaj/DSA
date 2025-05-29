#include<iostream>
#include <vector>
using namespace std;
//given array of integer print sum of all subsets
// no of subset =2^n
/* derivation of the formula
haar element ke pass do choice hai either to include or exclude therefore 1 se pass do choice similarly two and three hence 2*2*2-----upto n = 2^n
*/
//iterative solution
/*from geeks for geeks*/
/*#subset-> {1,2,3}
*/
void helper(vector<int>& v,vector<int>& subset,vector<vector<int>>& res,int index){
    //empty set enter
    res.push_back(subset);

    //recursively generate subsets by including and excluding element
    for(int i=index;i<v.size();i++){
        //include the cureent element in subset
        subset.push_back(v[i]);

        //add subsets in res using recursion with the curent elemeents included
        helper(v,subset,res,i+1);

        //excluding the cureent element
        //backtracking
        subset.pop_back();
    }
}

vector<vector<int>> pwset(vector<int>& v){
    vector<int> subset;
    vector<vector<int>> res;
    int index =0;
    int sum;
    helper(v,subset,res,index);
    return res;
}

void subset_sum(vector<int>& v,vector<int>& subset,int index,int sum){
    if(index==v.size(

    )) {
        subset.push_back(sum);
        return;
    }
    subset_sum(v,subset,index+1,sum+v[index]); //taking the element
    subset_sum(v,subset,index+1,sum); //not taking the element
}

vector<int> sum(vector<int>& v){
    vector<int> subset;
    int index= 0;
    int sum= 0;
    subset_sum(v,subset,index,sum);
    return subset;
}



int main(){
    vector<int> Vec={2,4};
    // vector<vector<int>> sub=pwset(Vec);
    vector<int> sub_sum=sum(Vec);
    // for(int i=0;i<sub.size();i++){
    //     cout<<"{";
    //     for(int j=0;j<sub[i].size();j++){
    //         cout<<sub[i][j]<<" ";
    //     }
    //     cout<<"}"<<endl;
    // }
    for(int i=0;i<sub_sum.size();i++){
        cout<<sub_sum[i]<<endl;
    }
}

//the problem is to count all the possible paths on on and m*n grid from top left to bottom right
int path(vector<vector<int>> V,int i1,int i2){
    if(i1==V.size()-1 && i2==V[0].size()-1) return 1;
    if(i1>=V.size() or i2>=V[0].size()) return 0;
    return path(V,i1+1,i2)+path(V,i1,i2+1);
}

int main(){
    vector<vector<int>> Vec={{1,2,3},{4,5,6},{7,8,9}};
    cout<<path(Vec,0,0);
}

int numberOfPaths(int m, int n)
{
	// We have to calculate m+n-2 C n-1 here
	// which will be (m+n-2)! / (n-1)! (m-1)!
	int path = 1;
	for (int i = n; i < (m + n - 1); i++) {
		path *= i;
		path /= (i - n + 1);
	}
	return path;
}

int main(){
	cout << numberOfPaths(3, 3);
	return 0;
}

// count the number of jumps
/*from starting to ending max jump can be of 6 (acc to dics)
0 to 3
path1 o 1 2 3
path2 0 1 3
path3 0 2 3
path4 0 3*/

int jumps(int start,int end,int key){
    if(start==end) return 1;
    if(start>end) return 0;
    int count=0;
    for(int i=1;i<=key;i++)
    count+=jumps(start+i,end,key);
    return count;
}

// int main(){
//     cout<<jumps(0,3,6);
// }

