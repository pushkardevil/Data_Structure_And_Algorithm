/////////////////////////////////////////////////////----------   RECURSION  ------------//////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int f(int i , int j , int n , vector<vector<int>>& triangle){
    //base case
    if(i == n-1) return triangle[n-1][j];
    
    int down=triangle[i][j] + f(i+1, j , n , triangle);
    int dia=triangle[i][j] + f(i+1 , j+1 , n , triangle);
    
    return min(down , dia);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    return f(0 , 0  , n , triangle); 
}


/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h> 
int f(int i , int j , int n , vector<vector<int>>& triangle , vector<vector<int>>&dp){
    //base case
    if(i == n-1) return triangle[n-1][j];
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int down=triangle[i][j] + f(i+1, j , n , triangle , dp );
    int dia=triangle[i][j] + f(i+1 , j+1 , n , triangle , dp);
    
    dp[i][j]=min(down , dia);
    return dp[i][j];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>>dp(n , vector<int>(n , -1));
    return f(0 , 0  , n , triangle , dp); 
}


///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>>dp(n , vector<int>(n , 0));
    for(int j=0;j<n;j++){
        dp[n-1][j] =triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j] + dp[i+1][j];
            int dia=triangle[i][j] + dp[i+1][j+1];
            dp[i][j]=min(down , dia);
        }
    }
    return dp[0][0]; 
}


///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int>front(n , 0) , curr(n , 0);
    for(int j=0;j<n;j++){
        front[j] =triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j] + front[j];
            int dia=triangle[i][j] + front[j+1];
            curr[j]=min(down , dia);
        }
        front=curr;
    }
    return front[0]; 
}
