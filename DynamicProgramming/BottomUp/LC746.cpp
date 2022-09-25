//746. Min Cost Climbing Stairs

class Solution { 
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> T(n+1,0);
        
        T[0]=cost[0], T[1]=cost[1];
        
        for(int i=2; i<n; i++){
            T[i]=cost[i]+min(T[i-1],T[i-2]);            
        }
        
        return min(T[n-1],T[n-2]);
    }
};

//optimised

class Solution { 
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev1=cost[1], prev2=cost[0];
        int curr=min(prev1,prev2);
        
        for(int i=2; i<n; i++){
            curr=cost[i]+min(prev1,prev2);        
            prev2=prev1;
            prev1=curr;
        }
        
        return min(prev2,prev1);
    }
};