/////////////////////////////////////////////////////----------   RECURSION  ------------///////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////---------- MEMOIZATION  ------------/////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////---------- TABULATION ------------////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////---------- SPACE OPTIMIZATION ------------////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h> 
long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(valueInHouse.size() ==1 ) return valueInHouse[0];
    
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<valueInHouse.size();i++){
        if(i != 0) v1.push_back(valueInHouse[i]);
        if(i != n-1) v2.push_back(valueInHouse[i]);
    }
    long long int ans1 = solve(v1);
    long long int ans2 = solve(v2);
   
    return max(ans1 , ans2);
}
