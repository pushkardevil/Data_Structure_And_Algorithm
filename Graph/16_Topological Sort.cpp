////////////////////////////////////  Topological Sort-----DFS       ////////////////////////////////

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int node , vector<int> adj[] , int vis[] , stack<int>&s){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(vis[it] == 0){
	            dfs(it , adj , vis , s);
	        }
	    }
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>topo;
	    stack<int>s;
	    int vis[V]={0};
	    
	    for(int i=0;i<V;i++){
	        if(vis[i] == 0){
	            dfs(i , adj ,vis , s);
	        }
	    }
	    
	    while(!s.empty()){
	        topo.push_back(s.top());
	        s.pop();
	    }
	    return topo;
	}
};


//////////////////////////////   Topological Sort----Knah Algoridhm       ////////////////////////////////
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	        
	        
	    }
	    return topo;
		
	}
};
