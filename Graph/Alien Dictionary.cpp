class Solution{
    public:
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
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            
            int mini=min(s1.size() , s2.size());
            for(int j=0;j<mini;j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        
        vector<int>topo=topoSort(K , adj);
        
        string ans="";
        for(int i=0;i<topo.size();i++){
            ans=ans+char(topo[i] + 'a');
        }
        
        return ans;
    }
};
