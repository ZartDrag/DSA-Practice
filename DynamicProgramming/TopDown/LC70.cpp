//70. Climbing Stairs

class Solution {
    
    vector<int> t;
    
    int Stairs(int n){
        if(n==0 || n==1) return 1;
        
        if(t[n]!=-1) return t[n];
        
        return t[n]=Stairs(n-1)+Stairs(n-2);
    }
    
public:
    int climbStairs(int n) {
        t.resize(n+1,-1);
        return Stairs(n);
    }
};