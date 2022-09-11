//154. Find Minimum in Rotated Sorted Array II

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l=0, h=nums.size()-1;
        int m=nums[0];
        
        if(h==0)
            return nums[0];
        
        while(l<=h){
            
            int mid = l+(h-l)/2;
            m=min(m,nums[mid]);
            
            if(nums[l]<=nums[mid] && nums[mid]<=nums[h]){
                h--;
            } else if(nums[l]<=nums[mid]){
                l=mid+1;
            } else {
                h=mid-1;
            }           
            
        }
        return m;
    }
};