//LINK---https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>v1(n , -1);
        vector<int>v2(n , -1);
        
        v1[0]=arr[0];
        for(int i=1;i<n;i++){
            v1[i]=max(v1[i-1] , arr[i]);
        }
        
        v2[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            v2[i]=max(v2[i+1] , arr[i]);
        }
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(v1[i], v2[i])-arr[i];
        }
        return sum;
    }
};
