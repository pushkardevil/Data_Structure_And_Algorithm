////////////////////////////////           DFS  TECHNIQUE TO DETECT CYCLE IN DIRECTED GRAPH ///////////////////////
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node , vector<int>adj[] , int vis[] , int pathvis[]){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it:adj[node]){
            if(vis[it] == 0){
                if(dfs(it , adj , vis , pathvis) == true) return true;
            }
            else if(pathvis[it] == 1){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                if(dfs(i , adj ,vis , pathvis) == true) return true;
            }
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    int cnt=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
	        //topo.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	        
	        
	    }
	    if(cnt == V){
	        return false;
	    }
	    else{
	        return true;
	    }
    }
};
