class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum=0, csum=0;
        int n=nums.size();
        for(auto itr:nums){
            sum+=itr;
        }
        
        int mini=1e9;
        int ans;
        for(int i=0;i<n;i++){
            csum+=nums[i];
            int avg1=csum/(i+1);
            if(i== n-1){
                if(avg1<mini){
                    return n-1;
                }
                else{
                    break;
                }
            }
            int avg2=(sum-csum)/(n-i-1);
            if(abs(avg1-avg2) < mini){
                mini=abs(avg1-avg2);
                ans=i;
            }
        }
        return ans;
    }
};
