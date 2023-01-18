class Solution {
public:
int largestRectangleArea(vector<int>& arr) {
        // NearestSmallestRight-index
        int n=arr.size();
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
        
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            ans=max(ans , (v1[i]-v2[i]-1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
         int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            
            result = max(result, largestRectangleArea(histogram));
        
        }
        return result;
    }
};
