/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
int solve(int indx , vector<int>&heights){
    //base case
    if(indx == 0) return 0;
    
    int left=solve(indx-1 , heights) + abs(heights[indx]- heights[indx-1]);
    int right=INT_MAX;
    if(indx >1){
        right=solve(indx-2 , heights) + abs(heights[indx]- heights[indx-2]);
    }
    
    return min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    return solve(n-1 , heights);
    
}


/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
int solve(int indx , vector<int>&heights , vector<int>&dp){
    //base case
    if(indx == 0) return 0;
    
    if(dp[indx] != -1){
        return dp[indx];
    }
    int left=solve(indx-1 , heights , dp) + abs(heights[indx]- heights[indx-1]);
    int right=INT_MAX;
    if(indx >1){
        right=solve(indx-2 , heights,dp) + abs(heights[indx]- heights[indx-2]);
    }
    
    dp[indx]=min(left , right);
    return dp[indx];
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1 , -1);
    return solve(n-1 , heights , dp);
    
}



///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n , -1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        
        dp[i]=min(fs , ss);
    }
    return dp[n-1];
    
}


///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
    int prev1=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev1+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=prev2+abs(heights[i]-heights[i-2]);
        }
        
        int curi=min(fs , ss);
        prev2=prev1;
        prev1=curi;
    }
    return prev1;
    
}
