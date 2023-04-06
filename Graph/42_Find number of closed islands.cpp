class Solution {
    public:
    void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<int>>&grid , int delrow[] , int delcol[] , int n , int m){
        vis[row][col]=1;
    
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
    
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                vis[nrow][ncol]=1;
                grid[nrow][ncol]=0;
                dfs(nrow , ncol , vis , grid, delrow , delcol,n , m);
            }
        }

}
    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        // Code here

        queue<pair<int,int>>q;
        int delrow[]={-1 , 0 , 1 , 0};
        int delcol[]={0 ,1 , 0 , -1 };


        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j== m-1){
                    if(grid[i][j] == 1){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({nrow , ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    dfs(i,j , vis , grid , delrow , delcol , n , m); 
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
