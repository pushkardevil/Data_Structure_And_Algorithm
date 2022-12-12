class Solution {
public:
bool solve(int i ,vector<int>adj[] , int col[] ){
        queue<int>q;
	    q.push(i);
	    col[i]=0;
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        for(auto it:adj[node]){
	            if( col[it] == -1 ){
	                col[it]= !col[node];
	                q.push(it);
	            }
	            else if(col[it] == col[node]){
	                return false;
	            }
	        }
	        
	    }
	    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    int col[V];
	    for(int i=0;i<V;i++){
	        col[i]=-1;
	    }
	    for(int i=0;i<V;i++){
	        if(col[i] == -1){
	            if(solve(i , adj  , col) == false){
	            return false;
	        }
	        }
	        
	    }
	    return true;
	    
	}

};
