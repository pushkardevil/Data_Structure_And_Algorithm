
bool isValid(vector<int>&A , int B , int mid){
    int student=1;
    int sum=0;
    
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum> mid){
            student++;
            sum=A[i];
        }
        
    }
    if(student > B) return false;
    
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(B > n) return -1;
    
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++) maxi=max(A[i] , maxi);
    for(int i=0;i<A.size();i++) sum+=A[i];
    
    int s=maxi;
    int e=sum;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isValid(A , B , mid) == true){
            res=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return res;
    
}
