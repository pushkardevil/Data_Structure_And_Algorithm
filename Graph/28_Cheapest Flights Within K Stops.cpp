class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        //{stops , {node , costs}}
        queue<pair<int , pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0, {src , 0}});
        dist[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int costs=it.second.second;
            
            if( stops > K) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edgeweight=it.second;
                
                if(costs + edgeweight < dist[adjnode] &&  stops <= K){
                    dist[adjnode]=costs +edgeweight;
                    q.push({stops+1 , {adjnode , costs +edgeweight}});
                }
            }
        }
        
        
        
        
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};
