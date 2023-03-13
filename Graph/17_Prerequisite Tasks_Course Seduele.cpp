class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[V];
	    for(auto it: prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    
	    
	    
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
	        return true;
	    }
	    else{
	        return false;
	    }
	}
};
