///////////////////////////////     Dijkstra Algorithm---- USING PRIORITY QUEUE      ///////////////////////////////

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<int>distance(V);
        for(int i=0;i<V;i++){
            distance[i]=1e9;
        }
        
        distance[S]=0;
        pq.push({0 , S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int edgeweight=it[1];
                int adjnode=it[0];
                
                if(dis+edgeweight < distance[adjnode]){
                    distance[adjnode]=dis+edgeweight;
                    pq.push({distance[adjnode] , adjnode});
                }
            }
        }
        return distance;
    }
};



//////////////////////////////     Dijkstra Algorithm---- USING SET      ///////////////////////////////
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>set;
        vector<int>distance(V);
        for(int i=0;i<V;i++){
            distance[i]=1e9;
        }
        distance[S]=0;
        set.insert({0 , S});
        
        while(!set.empty()){
            auto it=*(set.begin());
            int node=it.second;
            int dis=it.first;
            set.erase(it);
            
            for(auto it:adj[node]){
                int adjnode=it[0];
                int edgeweight=it[1];
                
                if(dis + edgeweight < distance[adjnode]){
                    // if exists erase it
                    if( distance[adjnode] != 1e9){
                        set.erase({distance[adjnode] , adjnode});
                    }
                    
                    distance[adjnode]=dis + edgeweight;
                    set.insert({distance[adjnode] , adjnode});
                    
                }
                
            }
        }
        return distance;
    }
};

