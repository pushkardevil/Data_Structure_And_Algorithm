class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        // 1 3 2 4
        vector<long long>v;
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            if(s.size() == 0){
                v.push_back(-1);
            }
            else if( s.top() > arr[i]){
                v.push_back(s.top());
            }
            else if( s.top() <= arr[i]){
                while(s.size() > 0 && s.top() <= arr[i]){
                    s.pop();
                }
                
                if(s.size() == 0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top());
                }
            }
            
            s.push(arr[i]);
            
        }
        
        reverse(v.begin(),v.end());
        return v;
        
        
    }
};
