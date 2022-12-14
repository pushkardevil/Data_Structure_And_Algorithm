/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int f(int i , int j1 , int j2 , int r , int c , vector<vector<int>> &grid){
    //base case
    if(j1 <0 || j1 >= c || j2 <0 || j2 >=c) return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    
    // now its time to explore all the path
    int maxi=0;
    for(int dj1=-1;dj1<= +1;dj1++){
        for(int dj2=-1;dj2<= +1;dj2++){
            int val=0;
            if(j1 == j2) val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=f(i+1 , j1+dj1 , j2+dj2 , r , c , grid);
            maxi=max(maxi , val);
        }
    }
    
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    return f(0 , 0 , c-1 , r , c , grid);
}

/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h> 
int f(int i , int j1 , int j2 , int r , int c , vector<vector<int>> &grid , vector<vector<vector<int>>>&dp){
    //base case
    if(j1 <0 || j1 >= c || j2 <0 || j2 >=c) return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    
    // now its time to explore all the path
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int maxi=-1e8;
    for(int dj1=-1;dj1<= +1;dj1++){
        for(int dj2=-1;dj2<= +1;dj2++){
            int val=0;
            if(j1 == j2) val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=f(i+1 , j1+dj1 , j2+dj2 , r , c , grid , dp);
            maxi=max(maxi , val);
        }
    }
    
    dp[i][j1][j2]=maxi;
    return dp[i][j1][j2];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // dp[r][c][c]
    vector<vector<vector<int>>>dp(r , vector<vector<int>>(c , vector<int>(c , -1)));
    return f(0 , 0 , c-1 , r , c , grid , dp);
}


///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////

