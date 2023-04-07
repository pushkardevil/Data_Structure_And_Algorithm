class Solution{
public:
void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>>&mat , int delrow[] , int delcol[]){
    vis[row][col]=1;
    
    int n=mat.size();
	int m=mat[0].size();
	
	for(int i=0;i<4;i++){
	    int nrow=row+delrow[i];
	    int ncol=col+delcol[i];
	    
	    if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O'){
	        vis[nrow][ncol]=1;
	        dfs(nrow , ncol , vis , mat , delrow , delcol);
	    }
	}
	    
	    
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
	    int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(mat[i][j] == 'O'){
                        dfs(i,j, vis , mat , delrow , delcol);
                    }
                }
                else if(mat[i][j] == 'X'){
                    vis[i][j]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && mat[i][j] == 'O'){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
    }
};
