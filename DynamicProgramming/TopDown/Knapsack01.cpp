class Solution
{
    vectorvectorint T;
    public
    
    int solve(int wt[], int val[], int W, int N){
        if(W==0  N==0){
            return 0;
        }
        
        if(T[N][W]!=-1) return T[N][W];
        
        if(wt[N-1]W){
            return T[N][W]=solve(wt,val,W,N-1);
        } else {
            return T[N][W]=max(solve(wt,val,W,N-1),val[N-1]+solve(wt,val,W-wt[N-1],N-1));
        }
    }
    Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        Your code here
       T.resize(n+1,vectorint(W+1,-1));
       
       return solve(wt,val,W,n);
    }
};