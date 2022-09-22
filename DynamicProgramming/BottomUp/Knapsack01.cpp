class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> T;
       T.resize(n+1,vector<int>(W+1,0));
       
       for(int i=1; i<=n; i++){
           for(int j=1; j<=W; j++){
                if(wt[i-1]>j)
                    T[i][j]=T[i-1][j];
                else{
                    T[i][j]=max(T[i-1][j], val[i-1] + T[i-1][j-wt[i-1]]);
                }
           }
       }
       return T[n][W];
    }
};