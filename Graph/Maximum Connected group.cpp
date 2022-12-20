#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
     
public: 
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        
        // step 1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) continue;
                int drow[]={-1 , 0 , 1 , 0};
                int dcol[]={0 , 1 , 0 , -1};
                
                for(int k=0;k<4;k++){
                    int nrow=i + drow[k];
                    int ncol=j + dcol[k];
                    if(nrow>=0 && nrow < n && ncol >=0 && ncol < n && grid[nrow][ncol] == 1){
                        int nodeNo=i*n+j;
                        int adjnode=nrow*n + ncol;
                        ds.unionBySize(nodeNo ,adjnode );
                    }
                }
            }
        }
        
        //step 2
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) continue;
                int drow[]={-1 , 0 , 1 , 0};
                int dcol[]={0 , 1 , 0 , -1};
                set<int>components;
                for(int k=0;k<4;k++){
                    int nrow=i + drow[k];
                    int ncol=j + dcol[k];
                    if(nrow>=0 && nrow < n && ncol >=0 && ncol < n ){
                        if(grid[nrow][ncol] == 1){
                            components.insert(ds.findUPar(nrow*n + ncol));
                        }
                        
                    }
                }
                
                int totalsize=0;
                for(auto it:components){
                    totalsize+=ds.size[it];
                }
                maxi=max(maxi , totalsize+1);
            }
        }
        
        for(int cellno=0;cellno<n*n ;cellno++){
            maxi=max(maxi , ds.size[ds.findUPar(cellno)]);
        }
        
        return maxi;
        
    }
};
