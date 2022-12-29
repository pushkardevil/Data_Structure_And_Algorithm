/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////
bool f(int i , int k , vector<int>&arr , vector<vector<int>>&dp){
    //base case
    if( k == 0) return true;
    if(i == 0) return (arr[i] == k);
    
    
    if(dp[i][k] != -1) return dp[i][k];
    bool ntake=f(i-1 , k , arr ,dp);
    bool take=false;
    if(k >= arr[i]){
        take=f(i-1 , k-arr[i] , arr , dp);
    } 
    
    dp[i][k]=(ntake || take);
    return dp[i][k];
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int totalsum=0;
    for(auto it:arr){
        totalsum+=it;
    }
    if(totalsum%2 == 1) return false;
    
    int k=totalsum/2;
    
    vector<vector<int>>dp(n , vector<int>(k+1 , -1));
    return f(n-1 , k , arr , dp);
}

///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////

