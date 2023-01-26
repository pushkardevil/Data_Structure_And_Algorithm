//LINK :https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    void solve(int i , int j , string s ,vector<vector<int>>&vis , vector<string>&ans ,
    vector<vector<int>>&m , int n){
        //base case
        if(i == n-1 && j == n-1){
            ans.push_back(s);
        }
        
        
        //downwards
        if(i+1 < n && i>=0 && vis[i+1][j] == 0 && m[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1 , j , s+'D' , vis , ans , m , n);
            vis[i][j]=0;
        }
        
        //left
        if(  j-1 >=0 && vis[i][j-1] == 0 && m[i][j-1]==1){
            vis[i][j]=1;
            solve(i , j-1 , s+'L' , vis , ans , m , n);
            vis[i][j]=0;
        }
        
        
        //right
        if(j+1 < n  && vis[i][j+1] == 0 && m[i][j+1]==1){
            vis[i][j]=1;
            solve(i, j+1, s+'R' , vis , ans , m , n);
            vis[i][j]=0;
        }
        
        
        //up
        if(i-1 >=0  && vis[i-1][j] == 0 && m[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1 , j , s+'U' , vis , ans , m , n);
            vis[i][j]=0;
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n , vector<int>(n , 0));
        
        if(m[0][0] == 1){
            solve(0 , 0 , "" , vis , ans , m , n);
        }
        return ans;
    }
};
