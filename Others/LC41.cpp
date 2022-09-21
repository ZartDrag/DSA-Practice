//41. First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        if(nums[0]>1) return 1;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>0){
                if(!(nums[i]+1==nums[i+1] || nums[i+1]==nums[i]))
                    return nums[i]+1;
            } else if(nums[i+1]>0 && nums[i+1]!=1){
                return 1;
            }
        }
        
        return nums[nums.size()-1]<0?1:nums[nums.size()-1]+1;
    }
};

//Alternate Solution

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int ans = 1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                if(nums[i]!=ans)
                    return ans;
                else if(i+1==nums.size() || nums[i+1]!=ans)
                    ans++;
            }
        }
        
        return ans;
    }
};