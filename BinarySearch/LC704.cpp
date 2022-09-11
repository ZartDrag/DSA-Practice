//704. Binary Search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int bot = 0, top = nums.size()-1;
        
        while(top>=bot){
            int mid = top + (bot-top)/2; //To avoid overflow
            if(target>nums[mid]){
                bot=mid+1;
            }else if(target<nums[mid]){
                top=mid-1;
            }else{
                return mid;
            }
        }
        
        return -1;
    }
};