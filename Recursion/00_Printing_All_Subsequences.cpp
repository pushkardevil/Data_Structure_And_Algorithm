
// input:
// arr[]={3 2 1};
// output :{{3 1 2}  , {3 1} , {3 , 2} , {3} , {1 ,2} , {1} , {2} , {} }.



#include<bits/stdc++.h>
using namespace std;

void solve(int ind , vector<int>&ds , int arr[] , int n){
	//base case
	if(ind == n){
		for(auto it:ds){
			cout<<it<<" ";
		}
		if(ds.size() == 0) cout<<"{}";
		cout<<endl;
		return;
	}
	
	//take or pick the particular index into the subsequence.
	ds.push_back(arr[ind]);
	solve(ind+1 , ds, arr , n);
	ds.pop_back();
	
	//not take condition
	solve(ind+1 , ds, arr , n);
}

int main(){
	int arr[]={3 , 1 , 2};
	int n=3;
	vector<int>ds;
	solve(0 ,ds , arr , n);
	return 0;
}
