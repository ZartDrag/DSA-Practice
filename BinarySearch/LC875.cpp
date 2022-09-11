//875. Koko Eating Bananas

class Solution {
    
    bool isSpeedViable(vector<int> piles, int hour, int mid){
        int CurrHours=0;
        
        for(int i=0; i<piles.size(); i++){            
            if(piles[i]>mid){
                CurrHours+=(piles[i]/mid)+(piles[i]%mid==0?0:1);
            } else {
                CurrHours++;
            }
            
            if(CurrHours>hour) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int hour) {
        int l=1;
        int h=*max_element(piles.begin(),piles.end());
        
        int res;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isSpeedViable(piles, hour, mid)){
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }
};