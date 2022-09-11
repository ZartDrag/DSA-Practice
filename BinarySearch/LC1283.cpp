//1283. Find the Smallest Divisor Given a Threshold

class Solution {
    
    bool crossesThreshold(vector<int> nums, int threshold, int mid){
        int sum=0;
        for(int i=0; i<nums.size(); i++) sum+=(nums[i]%mid!=0)?nums[i]/mid+1:nums[i]/mid;
        
        if(sum>threshold) return false;
        
        return true;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=*max_element(nums.begin(), nums.end());
        int res=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(crossesThreshold(nums, threshold, mid)){
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }
};