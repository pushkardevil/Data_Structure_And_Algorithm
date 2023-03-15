//////            striver solution          //////////////////
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,

                     pair<int, int> destination) {

        if(source.first == destination.first && source.second == destination.second) return 0;

        queue<pair<int, pair<int,int>>> q;

        int n = grid.size();

        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, 1e9));

        dist[source.first][source.second] = 0;

        q.push({0, {source.first, source.second}});

        int dr[] = {-1, 0, 1, 0};

        int dc[] = {0, 1, 0, -1};

        

        while(!q.empty()) {

            auto it = q.front();

            q.pop();

            int dis = it.first;

            int r = it.second.first;

            int c = it.second.second;

            for(int i=0; i<4; i++) {

                int newr = r + dr[i];

                int newc = c + dc[i];

                

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {

                    dist[newr][newc] = 1 + dis;

                    if(newr == destination.first && newc == destination.second) return dis + 1;

                    q.push({1 + dis, {newr, newc}});

                }

            }

        }

        return -1;

    }

};



////////////////////////////////     MY SOLUTION ////////////////////////////
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int , pair<int,int>>>q;
        vector<vector<int,int>>v(n , vector<int>(m , 1e9));
        v[source.first][source.second]=0;
        q.push({0 , {source.first , source.second}});
        
        
        int delrow[]={-1 , 0 , 1 , 0};
        int delcol[]={0 , 1 , 0 , -1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && grid[nrow][ncol] == 1 
                       && dis+1 < v[nrow][ncol){
                           v[nrow][ncol]=dis+1;
                           if(nrow == destination.first && ncol = destination.second){
                               return dis+1;
                           }
                           q.push({1+dis , {nrow , ncol}});
                    
                }
            }
        }
        return -1;
    }
};
