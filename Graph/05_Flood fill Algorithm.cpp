class Solution {
public:

void dfs(int row , int col , int iniColor , vector<vector<int>>&ans , vector<vector<int>>&image , int newColor){
    ans[row][col]=newColor;
    
    int n=image.size();
    int m=image[0].size();
    
    int delrow[]={-1 , 0 , 1 , 0};
    int delcol[]={0 , 1 , 0 , -1};
    
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        
        if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && ans[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
            dfs(nrow , ncol , iniColor , ans , image , newColor);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        
        dfs(sr , sc , iniColor , ans , image , newColor);
        return ans;
    }
};
