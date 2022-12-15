class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int dist[N];
        for(int i=0;i<N;i++){
            dist[i]=1e9;
        }
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        vector<int>sol(N , -1);
        for(int i=0;i<N;i++){
            if(dist[i] != 1e9){
                sol[i]=dist[i];
            }
        }
        
        return sol;
    }
};
