//287. Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int> arr) {
        
        for(int i=0; i<arr.size(); i++){
            if(arr[abs(arr[i])]<0) return abs(arr[i]);
            
            arr[abs(arr[i])]*=-1;
        }
        
        return -1;
    }
};