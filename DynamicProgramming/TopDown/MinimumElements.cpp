#include <bits/stdc++.h> 

int solve(vector<int> num, int x, vector<int> &T){
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    
    if(T[x]!=INT_MIN) return T[x];
    
    int mini=INT_MAX;    
    for(int i=0; i<num.size(); i++){
        int ans=solve(num, x-num[i],T);
        if(ans!=INT_MAX)
            mini=min(mini,1+ans);
    }
    return T[x]=mini;
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> T(x+1,INT_MIN);
    
    int ans= solve(num,x,T);
    return ans==INT_MAX?-1:ans;
}