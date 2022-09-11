//1482. Minimum Number of Days to Make m Bouquets

class Solution {
    
    bool hasBloomed(vector<int> bloomDay, int m, int k, int mid){
        int currM=0, currK=0;
        
        for(int i=0; i<bloomDay.size(); i++){
            
            if(bloomDay[i]<=mid){
                currK++;
            } else {
                currK=0;
            }
            
            if(currK>=k){
                currM++;
                currK=0;
                if(currM==m) return true;
            } 
        }
        
        return false;
    }
    
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int res=-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(hasBloomed(bloomDay, m, k, mid)){
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }
};