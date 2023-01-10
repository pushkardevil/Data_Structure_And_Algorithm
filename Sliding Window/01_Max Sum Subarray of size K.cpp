
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0;
        int j=0;
        long sum=0;
        long maxi=INT_MIN;
        
        while(j<Arr.size()){
            sum=sum+Arr[j];
            if(j-i+1 < K){
                j++;
            }
            else if(j-i+1 == K){
                maxi=max(sum , maxi);
                sum=sum-Arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};
