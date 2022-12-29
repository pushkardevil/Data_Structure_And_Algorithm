/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
bool f(int i , int k , vector<int>&arr){
    //base case
    if( k == 0) return true;
    if(i == 0) return (arr[i] == k);
    
    bool ntake=f(i-1 , k , arr);
    bool take=false;
    if(k >= arr[i]){
        take=f(i-1 , k-arr[i] , arr);
    }
    
    return (ntake || take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(n-1 , k , arr);
    
    
}

/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
bool f(int i , int k , vector<int>&arr , vector<vector<int>>&dp){
    //base case
    if( k == 0) return true;
    if(i == 0) return (arr[i] == k);
    
    
    if(dp[i][k] != -1) return dp[i][k];
    bool ntake=f(i-1 , k , arr , dp);
    bool take=false;
    if(k >= arr[i]){
        take=f(i-1 , k-arr[i] , arr , dp);
    } 
    
    dp[i][k]=(ntake || take);
    return dp[i][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    //dp[index][target]
    vector<vector<int>>dp(n , vector<int>(k+1 , -1));
    return f(n-1 , k , arr , dp);
    
    
}

///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    //dp[index][target]
    vector<vector<bool>>dp(n , vector<bool>(k+1 , 0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool ntake=dp[ind-1][target];
            bool take=false;
            if(target >= arr[ind]){
                take=dp[ind-1][target-arr[ind]];
            }
            
            dp[ind][target]=(take || ntake);
        }
    }
    return dp[n-1][k];
}


///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////

