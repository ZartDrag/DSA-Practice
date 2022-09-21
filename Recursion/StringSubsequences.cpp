#include <bits/stdc++.h> 

void solve(string str, string output, vector<string> &ans, int i){
    if(i>=str.length()){
        if(!output.empty())
            ans.push_back(output);
        return;
    }
    
    solve(str, output, ans, i+1);
    output+=str[i];
    solve(str, output, ans, i+1);
}
vector<string> subsequences(string str){
	
	// Write your code here
    vector<string> ans;
    string output = ""; 
    solve(str, output, ans, 0);
    return ans;	
}
