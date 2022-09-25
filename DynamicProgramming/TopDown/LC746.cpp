class Solution {
    
    vector<int> T;
    
    int solve(vector<int> cost, int n){
        if(n==1 || n==0) return cost[n];
        
        if(T[n]!=-1) return T[n];
        
        return T[n]=cost[n]+min(solve(cost, n-1), solve(cost, n-2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        T.resize(cost.size(),-1);
        return min(solve(cost, cost.size()-1), solve(cost, cost.size()-2));
    }
};