//1680. Concatenation of Consecutive Binary Numbers (Bit Manip)

class Solution {
public:
    int concatenatedBinary(int n) {
        long mod = 1e9+7, ans=0;
        int len=0;
        for(int i=1; i<=n; i++){
            if(!(i & (i-1))) len++;
            
            ans=((ans<<len)+i)%mod;                
        }
        return ans;
    }
};