class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        vector<int> cf;
        cf.push_back(0);
        for(int i=0; i<nums.size(); i++)
            cf.push_back(cf[i]+nums[i]);
        
        int res=INT_MAX;
        
        for(int i=0; i<cf.size(); i++){
            int l=i+1, h=nums.size(); //since nums.size()+1==cf.size()
            
            while(l<=h){
                int mid=l+(h-l)/2;
                if(cf[mid]-cf[i]>=target){
                    res=min(res,mid-i);
                    h=mid-1;
                } else {
                    l=mid+1;
                }
            }
        }
        
        return res==INT_MAX?0:res;
    }
};