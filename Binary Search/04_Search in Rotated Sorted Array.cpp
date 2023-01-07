////////////////////////////////////////              YE MERA CODE HAI PTA NAHI KYU NAHI CHAL RHA


class Solution {
public:
int binarySearch(vector<int>arr , int s , int e , int key){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }
    }
    return -1;

}
int findKRotation(vector<int>arr, int n) {
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
	    return -1;
	}
    int search(vector<int>& nums, int key) {
        int n=nums.size();

        int pivot=findKRotation(nums , n);
        if (pivot == -1){
            return binarySearch(nums, 0, n - 1, key);
        }
               
 
        // If we found a pivot, then first compare with pivot
        // and then search in two subarrays around pivot
        if (nums[pivot] == key)
            return pivot;
    
        if (nums[0] <= key)
            return binarySearch(nums, 0, pivot - 1, key);
 
        return binarySearch(nums, pivot + 1, n - 1, key);
        

    }
};























/////////////////////////////////////////
class Solution {
public:
    int findMin(vector<int>& nums){
        int n = nums.size(), start = 0, end = n - 1, mid;
        while(start <= end){
            if(nums[start] < nums[end]) return start;
            mid = start + (end - start) / 2;
            if(nums[mid] <= nums[(mid + n - 1) % n]) return mid;
            else if(nums[start] <= nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target){
        int n = nums.size(), minPos = findMin(nums);
        if(binarySearch(nums, target, 0, minPos - 1) != -1) return binarySearch(nums, target, 0, minPos - 1);
        return binarySearch(nums, target, minPos, n - 1);
    }
};
