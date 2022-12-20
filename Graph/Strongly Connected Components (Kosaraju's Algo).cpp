class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs( int node , vector<int>&vis , vector<int>adj[] , stack<int>&s){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(vis[it] == 0){
	            dfs(it , vis , adj , s);
	        }
	    }
	    
	    s.push(node);
	}
	
	void dfs2( int node , vector<int>&vis , vector<int>Tadj[] ){
	    vis[node]=1;
	    for(auto it:Tadj[node]){
	        if(vis[it] == 0){
	            dfs2(it , vis , Tadj );
	        }
	    }
	    
	   
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //step1
        stack<int>s;
        vector<int>vis(V , 0);
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                dfs(i , vis , adj , s);
            }
        }
        
        //step2;
        vector<int>Tadj[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                //i---it
                //it----i
                Tadj[it].push_back(i);
            }
        }
        
        //step3
        int scc=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(vis[node] == 0){
                scc++;
                dfs2(node , vis , Tadj);
            }
            
        }

        
        
        return scc;
        
    }
};
