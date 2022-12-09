class Solution{
public:

void dfs(int row , int col ,vector<vector<int>>&vis ,vector<vector<char>>&mat, int delrow[] , int delcol[]){
    vis[row][col]=1;
    int n=mat.size();
    int m=mat[0].size();
    
    //check for top,right,bottom,left.
    for(int i=0;i<4;i++){
        int nrow=row + delrow[i];
        int ncol=col + delcol[i];
        
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 1 && mat[nrow][ncol] == 'O'){
            dfs(nrow , ncol , vis , mat , delrow , delcol);
        }
    }
}

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n , vector<int>(m ,0));
        int delrow[]={-1 , 0 , 1 , 0};
        int delcol[]={0 ,1 , 0 , -1 };
        // traverse first and last row.
        for(int i=0;i<m;i++){
            //first row
            if(vis[0][i] != 1 && mat[0][i] == 'O'){
                dfs(0 , i , vis , mat , delrow , delcol);
            }
            
            //last row
            if(vis[n-1][i] != 1 && mat[n-1][i] == 'O'){
                dfs(n-1 , i , vis , mat , delrow , delcol);
            }
            
        }
        
        // traverse first and last column.
        for(int i=0;i<n;i++){
            //first row
            if(vis[i][0] != 1 && mat[i][0] == 'O'){
                dfs(i , 0 , vis , mat , delrow , delcol);
            }
            
            //last row
            if(vis[i][m-1] != 1 && mat[i][m-1] == 'O'){
                dfs(i , m-1 , vis , mat , delrow , delcol);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( vis[i][j] != 1 && mat[i][j] == 'O'){
                    mat[i][j] ='X';
                }
            }
        }
        
        return mat;
    }
};
