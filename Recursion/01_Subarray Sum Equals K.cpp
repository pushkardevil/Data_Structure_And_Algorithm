
#include<bits/stdc++.h>
using namespace std;

void solve(int ind , vector<int>&ds , int s , int sum ,  int arr[] , int n){
	//base case
	if(ind == n){
		if(s == sum){
			for(auto it:ds) cout<<it<<" ";
			cout<<endl;
		}
		return;
	}
	
	//take or pick the particular index into the subsequence.
	ds.push_back(arr[ind]);
	s+=arr[ind];
	solve(ind+1 , ds,s , sum , arr , n);
	s-=arr[ind];
	ds.pop_back();
	
	//not take condition
	solve(ind+1 , ds,s , sum , arr , n);
}

int main(){
	int arr[]={ 1 , 2 , 1};
	int n=3;
	int sum=2;
	vector<int>ds;
	solve(0 ,ds ,0 , sum, arr , n);
	return 0;
}
