class Solution {
public:
int ans;
    void dfs( int i ,int j ,vector<vector<int>>& grid ,vector<vector<bool>>&vis , int cnt){
        //base case
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] == 1 || grid[i][j] == -1){
            return;
        }

        if(grid[i][j] == 2  && cnt == 0){
            ans++;
        }

        vis[i][j]=1;
        cnt--;

        dfs(i-1 , j , grid , vis , cnt);
        dfs(i , j+1 , grid , vis , cnt);
        dfs(i+1 , j , grid , vis , cnt);
        dfs(i , j-1, grid , vis , cnt);

        vis[i][j]=0;
        cnt++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m , vector<bool>(n  , 0));
        int ii,jj;
        int cnt=0;
        ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 ){
                    cnt++;
                }

                if(grid[i][j] == 1){
                    cnt++;
                    ii=i;
                    jj=j;
                }
            }
        }

        dfs(ii , jj , grid , vis , cnt);

        return ans;
    }
};
