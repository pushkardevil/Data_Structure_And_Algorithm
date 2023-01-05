class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        int vis[n][m];
        //{{row, col} , time}
        queue<pair<pair<int,int> , int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=1;
                }
            }
        }
        
        int time=0;
        int delrow[]={-1 , 0 , 1 , 0};
        int delcol[]={0 , 1 , 0 , -1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(t , time);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&  vis[nrow][ncol] !=2  && grid[nrow][ncol] == 1){
                    q.push({{nrow , ncol} , t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }
        
        
        return time;
    }
};
