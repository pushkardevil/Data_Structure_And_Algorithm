/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

int f(int n){
	if(n<=1) return n;
	
	return f(n-1)+f(n-2);
}
int main(){
	int n;
	cin>>n;
	
	cout<<f(n)<<endl;
	return 0;
}
/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int>&dp){
	//base case
	if(n<=1) return n;
	
	if(dp[n] != -1){
		return dp[n];
	}
	dp[n]= f(n-1 , dp)+f(n-2 , dp);
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	
	vector<int>dp(n+1 , -1);
	
	cout<<f(n , dp)<<endl;
	return 0;
}

///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int>dp(n+1 , -1);
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	
	cout<<dp[n]<<endl;
	return 0;
}


///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int prev1=1;
	int prev2=0;
	
	
	for(int i=2;i<=n;i++){
		int curr=prev1+prev2;
		prev2=prev1;
		prev1=curr;
	}
	
	cout<<prev1<<endl;
	return 0;
}

