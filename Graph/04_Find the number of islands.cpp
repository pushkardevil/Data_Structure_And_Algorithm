///////////////////////////////////////////////////////////         BFS                  ////////////////////////////////////////////////////////////////////

void bfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<int , int>q;
        q.push({row , col});
        int n=grid.size();
        int m=gris[0].size();
        
        while( !q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            // and then we have to traverse in neighbour and mark them if it is a land.
            for(int delrow=-1 ; delrow <=1;delrow++){
                for(int delcol=-1 ; delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol >= 0 && ncol <= m && grid[nrow]][ncol] = '1' && vis[nrow][ncol != 1]){
                        vis[nrow][ncol]=1;
                        q.push({nrow , ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=gris[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(vis[row][col] != 1 && vis[row][col] == 1){
                    cnt++;
                    bfs(row , col , vis , grid);
                }
            }
        }
        
        return cnt;
    }


////////////////////////////////////////////////////////     DFS          //////////////////////////////////////////////////////////////////////
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>>&grid){
        vis[row][col]=1;
    
        int n=grid.size();
        int m=grid[0].size();
        
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow=row+delrow;
                int ncol=col+delcol;
                
                if(nrow>=0 && nrow< n && ncol >=0 && ncol <m && grid[nrow][ncol] =='1' && vis[nrow][ncol] == 0){
                    dfs(nrow , ncol , vis , grid);
                }
            }
    }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n , vector<int>(m , 0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(vis[row][col] == 0 && grid[row][col] == '1'){
                    cnt++;
                    dfs(row , col , vis , grid);
                }
            }
        }
        return cnt;
    }
};
