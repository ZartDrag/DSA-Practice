//410. Split Array Largest Sum

class Solution {
    
    bool isSumPossible(vector<int>& nums, int m, int mid){
        int currSum=0, currSubs=1;
        
        for(int i=0; i<nums.size(); i++){
            if(currSum+nums[i]>mid){
                currSubs++;
                if(currSubs>m) return false;
                currSum=nums[i];
            } else {
                currSum+=nums[i];
            }
        }
        
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int res;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isSumPossible(nums, m, mid)){
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }
};