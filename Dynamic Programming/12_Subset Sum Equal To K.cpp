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



///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////

