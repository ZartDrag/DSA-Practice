//852. Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l=1, h=arr.size()-2;
        
        while(l<=h){
            int mid = l + (h - l)/2;
            
            if(arr[mid-1]<arr[mid]){
                if(arr[mid]>arr[mid+1])
                    return mid;
                l=mid+1;
            } else h=mid-1;
        }
        
        return -1;
    }
};