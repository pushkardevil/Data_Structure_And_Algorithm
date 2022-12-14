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
