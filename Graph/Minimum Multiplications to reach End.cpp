class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // {steps , num}
        queue<pair<int,int>>q;
        q.push({start , 0});
        
        vector<int>dist(100000 , 1e4);
        dist[0]=0;
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            for(auto it:arr){
                int num=(it*node)%100000;
                
                if(steps+1 < dist[num]){
                    dist[num]=steps+1;
                    if(num == end) return steps+1;
                    q.push({num , steps+1});
                }
            }
            
            
        }
        return -1;
    }
};
