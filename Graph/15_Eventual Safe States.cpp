class Solution {
  public:
  bool dfscyclecheck(int node ,vector<int> adj[] , int vis[], int pathvis[] , int check[] ){
      vis[node]=1;
      pathvis[node]=1;
      check[node]=0;
      
      for(auto it:adj[node]){
          if(vis[it] == 0){
              if(dfscyclecheck(it , adj , vis , pathvis , check) == true){
                  check[node]=0;
                  return true;
              }
          }
          else if( pathvis[it] == 1){
              return true;
          }
      }
      
      check[node]=1;
      pathvis[node]=0;
      return false;
  }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathvis[V]={0};
        int check[V]={0};
        
        vector<int>safenode;
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                dfscyclecheck(i , adj , vis , pathvis , check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i] == 1){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};



//////////////////////////////////////     Eventual Safe States-------By Topological sort ////////////////////////////////////////////////////////

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>Revadj[V];
        vector<int>indegree(V , 0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                Revadj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        
    //     for(int i=0;i<V;i++){
	   //     for(auto it:adj[i]){
	   //         indegree[it]++;
	   //     }
	   // }
	    
	    
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        
        vector<int>safenode;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenode.push_back(node);
            
            for(auto it:Revadj[node]){
                indegree[it]--;
                if( indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        sort(safenode.begin() , safenode.end());
        return safenode;
    }
};
