//367. Valid Perfect Square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return 1;        
        int l=1, h=num/2;        
        while(l<=h){
            int mid=l+(h-l)/2;
            long sq=1L*mid*mid;
            if(sq<num) l=mid+1;
            else if(sq>num) h=mid-1;
            else return true;
        }
        
        return false;
    }
};