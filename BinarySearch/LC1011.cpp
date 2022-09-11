//1011. Capacity To Ship Packages Within D Days

class Solution {
    
    bool isShippingPossible(vector<int>& weights, int days, int max_weight){
        
        int currDay=1, currWeight=0;
        
        for(int i=0; i<weights.size(); i++){
            
            if(max_weight<weights[i]) return false;
            
            if(currWeight+weights[i]>max_weight){
                currDay++;
                if(currDay>days) return false;
                currWeight=weights[i];
            } else {
                currWeight+=weights[i];
            }
        }        
        
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*min_element(weights.begin(), weights.end());
        int h=accumulate(weights.begin(), weights.end(),0);
        int res;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isShippingPossible(weights, days, mid)){
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }
};