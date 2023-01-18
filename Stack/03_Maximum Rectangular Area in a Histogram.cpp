class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        // NearestSmallestRight-index
        vector<int>v1;
        stack<pair<int , int>>s1;
        for(int i=n-1;i>=0;i--){
            if(s1.size() == 0){
                v1.push_back(n);
            }
            else if(s1.top().first < arr[i]){
                v1.push_back(s1.top().second);
            }
            else if(s1.top().first >= arr[i]){
                while(s1.size() > 0 && s1.top().first >= arr[i]){
                    s1.pop();
                }
                
                if(s1.size() == 0){
                    v1.push_back(n);
                }
                else{
                    v1.push_back(s1.top().second);
                }
            }
            
            s1.push({arr[i] , i});
        }
        
        reverse(v1.begin() , v1.end());
        
        // NearestSmallestLeft-index
        vector<int>v2;
        stack<pair<int , int>>s2;
        for(int i=0;i<n;i++){
            if(s2.size() == 0){
                v2.push_back(-1);
            }
            else if(s2.top().first < arr[i]){
                v2.push_back(s2.top().second);
            }
            else if(s2.top().first >= arr[i]){
                while(s2.size() >0 && s2.top().first >= arr[i]){
                    s2.pop();
                }
                
                if(s2.size() == 0){
                    v2.push_back(-1);
                }
                else{
                    v2.push_back(s2.top().second);
                }
            }
            
            s2.push({arr[i] , i});
        }
        
        
        long long ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            ans=max(ans , (v1[i]-v2[i]-1)*arr[i]);
        }
        return ans;
        
    }
};
