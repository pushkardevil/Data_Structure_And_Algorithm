class Solution
{
    public: 
    void rightOccurences(vector<long long> v , long long x , long &res2){
        int s=0;
        int e=v.size()-1;
        
        while(s <= e){
            int mid=s+(e-s)/2;
            
            if(v[mid] == x){
                res2=mid;
                s=mid+1;
            }
            else if(v[mid] > x) e=mid-1;
            else s=mid+1;
        }
    }
    void leftOccurences(vector<long long> v , long long x , long &res1){
        int s=0;
        int e=v.size()-1;
        
        while(s <= e){
            int mid=s+(e-s)/2;
            
            if(v[mid] == x){
                res1=mid;
                e=mid-1;
            }
            else if(v[mid] > x) e=mid-1;
            else s=mid+1;
        }
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int s=0;
        int e=v.size()-1;
        long res1=-1;
        long res2=-1;
        
        leftOccurences(v , x , res1);
        rightOccurences(v , x , res2);
        return {res1,res2};
    }
};
