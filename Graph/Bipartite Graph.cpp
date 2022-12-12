///////////////////////////////////	BFS      //////////////////////////////////////

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



/////////////////////////////////      DFS    /////////////////////////////////////////
class Solution {
public:
bool dfs(int node , int col , vector<int>&colour , vector<int>adj[]){
    colour[node]=col;
    for(auto it:adj[node]){
        if( colour[it] == -1){
            if(dfs(it , !col , colour , adj) == false){
                return false;
            }
        }
        else if( colour[it] == colour[node]){
            return false;
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>colour(V , -1);
	    for(int i=0;i<V;i++){
	        if(colour[i] == -1){
	            if(dfs(i , 0 , colour , adj) == false){
	                return false;
	            }
	            
	        }
	    }
	    return true;
	}

};
