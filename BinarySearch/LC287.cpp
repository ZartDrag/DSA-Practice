//287. Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=0, h=nums.size();
        int res;
        while(l<=h){
            int mid=l+(h-l)/2, smol=0;
            
            for(int i=0; i<nums.size(); i++)        
                if(nums[i]<=mid)
                    smol++;
            
            if(smol>mid){
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }
};