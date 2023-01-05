class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        int ans=0;

        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }

                if(grid[i][j] == 1) c++;
            }
        }

        while(!q.empty()){
            int s=q.size();
            if(c == 0) return ans;

            while(s--){
                auto a=q.front();
                q.pop();

                int i=a.first;
                int j=a.second;

                if(i >0){
                    if(grid[i-1][j] == 1){
                        c--;
                        grid[i-1][j] = 2;
                        q.push({i-1,j});
                    }
                }

                if(j >0){
                    if(grid[i][j-1] == 1){
                        c--;
                        grid[i][j-1] = 2;
                        q.push({i,j-1});
                    }
                }

                if(i < n-1){
                    if(grid[i+1][j] == 1){
                        c--;
                        grid[i+1][j] = 2;
                        q.push({i+1,j});
                    }
                }

                if(j < m-1){
                    if(grid[i][j+1] == 1){
                        c--;
                        grid[i][j + 1] = 2;
                        q.push({i,j + 1});
                    }
                }
                
            }
            ans++;

        }

        return c==0?ans:-1;
    }
};
