/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>  
int f(int i , int j , vector<vector<int>> &grid){
    //base case
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    
    int up= grid[i][j] + f(i-1 , j , grid);
    int left = grid[i][j] + f(i , j-1 , grid);
    return min(up , left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    return f(n-1 , m-1 , grid);
}

/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>  
int f(int i , int j , vector<vector<int>> &grid , vector<vector<int>>&dp){
    //base case
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    
    if(dp[i][j] != -1) return dp[i][j];
    int up= grid[i][j] + f(i-1 , j , grid , dp );
    int left = grid[i][j] + f(i , j-1 , grid , dp);
    dp[i][j]=min(up , left);
    
    return dp[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n , vector<int>(m , -1)); 
    return f(n-1 , m-1 , grid , dp);
}



///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>  

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n , vector<int>(m , -1)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0) dp[i][j]=grid[i][j];
            else{
                int up=grid[i][j];
                int left=grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;
                
                if(j>0) left+=dp[i][j-1];
                else left+=1e9;
                
                dp[i][j]=min(up , left);
            }
        }
    }
    return dp[n-1][m-1];
}

///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////

