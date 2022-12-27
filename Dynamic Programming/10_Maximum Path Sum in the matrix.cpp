/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int f(int i,int j , vector<vector<int>> &triangle){
    //base case
    if( j < 0 || j >= triangle[0].size()) return -1e8;
    if(i == 0) return triangle[0][j];
    
    
    int up=triangle[i][j] + f(i-1 , j , triangle);
    int dl=triangle[i][j] + f(i-1 , j-1 , triangle);
    int dr=triangle[i][j] + f(i-1 , j+1 , triangle);
    
    return max(up , max(dl , dr));
}
int getMaxPathSum(vector<vector<int>> &triangle)
{
    int n=triangle.size();
    int m=triangle[0].size();
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi ,f(n-1 , j , triangle));
    }
     
     return maxi;
                 
              
}

/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int f(int i,int j , vector<vector<int>> &triangle , vector<vector<int>>&dp){
    //base case
    if( j < 0 || j >= triangle[0].size()) return -1e8;
    if(i == 0) return triangle[0][j];
    
    
    if(dp[i][j] != -1) return dp[i][j];
    int up=triangle[i][j] + f(i-1 , j , triangle , dp);
    int dl=triangle[i][j] + f(i-1 , j-1 , triangle , dp);
    int dr=triangle[i][j] + f(i-1 , j+1 , triangle , dp);
    
    return dp[i][j]=max(up , max(dl , dr));
   // return dp[i][j];
}
int getMaxPathSum(vector<vector<int>> &triangle)
{
    int n=triangle.size();
    int m=triangle[0].size();
    int maxi=-1e8;
    
    vector<vector<int>>dp(n , vector<int>(m , -1));
    for(int j=0;j<m;j++){
        maxi=max(maxi ,f(n-1 , j , triangle , dp));
    }
     
     return maxi;        
}



///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &triangle)
{
    int n=triangle.size();
    int m=triangle[0].size();
    int maxi=-1e8;
    
    vector<vector<int>>dp(n , vector<int>(m , -1));
    for(int j=0;j<m;j++) dp[0][j]=triangle[0][j];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=triangle[i][j] + dp[i-1][j];
            int dl=triangle[i][j];
            if(j-1>=0) dl+=dp[i-1][j-1];
            else dl+=-1e8;
            
            int dr=triangle[i][j];
            if(j+1 <m) dr+=dp[i-1][j+1];
            else dr+=-1e8;
            
            dp[i][j]=max(up , max(dl , dr));
        }
    }
    
    for(int j=0;j<m;j++){
        maxi=max(maxi , dp[n-1][j]);
    }
    
     
     return maxi;        
}


///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &triangle)
{
    int n=triangle.size();
    int m=triangle[0].size();
    int maxi=-1e8;
    
    vector<int>prev(m , 0) , curr(m , 0);
    for(int j=0;j<m;j++) prev[j]=triangle[0][j];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=triangle[i][j] + prev[j];
            int dl=triangle[i][j];
            if(j-1>=0) dl+=prev[j-1];
            else dl+=-1e8;
            
            int dr=triangle[i][j];
            if(j+1 <m) dr+=prev[j+1];
            else dr+=-1e8;
            
            curr[j]=max(up , max(dl , dr));
        }
        prev=curr;
    }
    
    for(int j=0;j<m;j++){
        maxi=max(maxi , prev[j]);
    }
    
     
     return maxi;        
}
