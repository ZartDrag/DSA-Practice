//2089. Find Target Indices After Sorting Array

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        
        sort(nums.begin(), nums.end());
        
        if(n==1){
            if(nums[0]==target)
                return {0};
            else
                return {};
        }
        
        int l=0, h=n-1, ind=-1;
        
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(nums[mid]==target){
                ind=mid;
                h=mid-1;
            } else if(target<nums[mid]){
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        if(ind==-1){
            return {};
        }
        
        vector<int> ans;
        
        for(int i=ind; nums[i]==target; i++)
            ans.push_back(i);
        
        return ans;
    }
};