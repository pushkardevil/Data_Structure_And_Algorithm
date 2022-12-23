/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int solve(int indx , vector<int>&nums){
    //base case
    if(indx == 0) return nums[indx];
    if(indx <0) return 0;
    
    int pick= nums[indx] + solve(indx-2, nums);
    int npick=0 + solve(indx-1 , nums);
    
    return max(pick , npick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    return solve(n-1 , nums);
}


/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int solve(int indx , vector<int>&nums , vector<int>&dp){
    //base case
    if(indx == 0) return nums[indx];
    if(indx <0) return 0;
    
    if(dp[indx] != -1){
        return dp[indx];
    }
    int pick= nums[indx] + solve(indx-2, nums , dp);
    int npick=0 + solve(indx-1 , nums , dp);
    
    dp[indx]=max(pick , npick);
    return dp[indx];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1 , -1); 
    return solve(n-1 , nums , dp);
}



///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1 , -1);
    dp[0]=nums[0];
    int neg=0;
    
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1){
            pick=pick+dp[i-2];
        }
        
        int nonpick=dp[i-1];
        
        dp[i]=max(pick ,nonpick);
    }
    return dp[n-1];
}


///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int prev1=nums[0];
    int prev2=0;
    
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1){
            pick=pick+ prev2;
        }
        
        int npick=0+prev1;
        
        int curri=max(pick , npick);
        prev2=prev1;
        prev1=curri;
    }
    return prev1;
}
