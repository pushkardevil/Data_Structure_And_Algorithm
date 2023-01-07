class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int s=0;
	    int e=n-1;
	    
	    while(s<=e){
	        int mid=s+(e-s)/2;
	        int prev=(mid+n-1)%n;
	        int next=(mid+1)%n;
	        
	        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
	            return mid;
	        }
	        
	        if(arr[mid]>=arr[0]){
	            s=mid+1;
	        }
	        else if(arr[mid] <= arr[n-1]){
	            e=mid-1;
	        }
	        
	    }
	    return 0;
	}

};
