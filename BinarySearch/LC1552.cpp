//1552. Magnetic Force Between Two Balls

class Solution {
    bool isOrientationPossible(vector<int> position, int m, int min){
        
        int currM=1;
        
        for(int i=1, j=0; i<position.size(); i++){
            int mag=position[i]-position[j];
            
            if(mag>=min){
                currM++;                
                if(currM==m) return true;
                j=i;
            }
        }
        
        return false;       
        
    }
    
    
public:
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        
        int l=0, h=position[position.size()-1]-position[0];
        int res=-1;
        
        if(position.size()==1) return position[0];
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isOrientationPossible(position, m, mid)){
                res=mid;
                l=mid+1;
            } else {
                h=mid-1;
            }
        }
        
        return res;
    }
};