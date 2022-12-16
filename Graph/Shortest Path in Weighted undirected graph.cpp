class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<int>distance(n+1 , 1e9);
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        distance[1]=0;
        pq.push({0 , 1});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edgeweight=it.second;
                if( dis + edgeweight < distance[adjnode]){
                    distance[adjnode]=dis + edgeweight;
                    pq.push({distance[adjnode] , adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        
        if(distance[n] == 1e9){
            return {-1};
        }
        
        vector<int>path;
        int node=n;
        while(parent[node] != node){
            path.push_back(node);
            node=parent[node];
        }
        
        path.push_back(1);
        reverse(path.begin() , path.end());
        return path;
        
        
        
        return distance;
    }
};
