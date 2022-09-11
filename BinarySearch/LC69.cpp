//69. Sqrt(x)
int mySqrt(int x) {
        
        if(x==0)
            return 0;
        
        int l=1, h=x/2, ans=1;
        
        while(l<=h){
            long mid=l+(h-l)/2;
            long m2=mid*mid;
            if(m2==x)
                return mid;
            else if(m2<x){
                ans=mid;
                l=mid+1;
            } else {
                h=mid-1;
            }
        }
        
        return ans;
    }