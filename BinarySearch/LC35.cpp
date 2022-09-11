//35. Search Insert Position

int searchInsert(vector<int>& nums, int target) {
        
        if(target<nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        
        int mid;
        int l=0, h=nums.size()-1;
        
        while(l<=h){
            mid=l+(h-l)/2;
            
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        
        if(nums[mid]<target) return mid+1;
        else return mid;
    }