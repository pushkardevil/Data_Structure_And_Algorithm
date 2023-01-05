class Solution {
  public:
    // Function to detect cycle in an undirected graph
    bool detectcycle(int src , vector<int> adj[] , int vis[]){
        vis[src]=1;
        queue<pair<int , int>>q;
        q.push({src , -1});
        
        while(!q.empty()){
            auto a=q.front();
            int node=a.first;
            int parent=a.second;
            q.pop();
            
            for(auto it:adj[node]){
                if(vis[it] != 1){
                    vis[it]=1;
                    q.push({it , node});
                }
                else if( parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(vis[i] != 1){
                if(detectcycle(i , adj , vis)) return true;
            }
        }
        return false;
    }
};
