//34. Find First and Last Position of Element in Sorted Array

vector<int> searchRange(vector<int>& nums, int target) {
        
        int l=0, h=nums.size()-1;
        int spos=-1,epos=-1;
        
        while(l<=h){    //To find first position
            
            int mid = l+(h-l)/2;
            
            if(nums[mid]==target){
                spos=mid;
                h=mid-1;
            } else if(target<nums[mid]){
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        l=0, h=nums.size()-1;
        
        while(l<=h){    //To find last position
            
            int mid = l+(h-l)/2;
            
            if(nums[mid]==target){
                epos=mid;
                l=mid+1;
            } else if(target<nums[mid]){
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return {spos,epos};
    }