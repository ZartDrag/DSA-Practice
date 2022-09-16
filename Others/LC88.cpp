//88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, k=0;
        
        vector<int> nums;
        nums.assign(nums1.begin(), nums1.begin()+m);
        
        while( i<m && j<n )
            nums1[k++]=nums[i]<nums2[j]?nums[i++]:nums2[j++];
        
        
        while(i<m)
            nums1[k++]=nums[i++];
        
        while(j<n)
            nums1[k++]=nums2[j++];
    }
};