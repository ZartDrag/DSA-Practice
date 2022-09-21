#include <bits/stdc++.h> 

vector<string> subsequences(string str){	
	// Write your code here
    
    vector<string> ans;
    
    for(int i=0; i<(1<<str.length()); i++){
        string temp;
        for(int j=0; j<str.length(); j++){
            if(i & (1<<j))
                temp+=str[j];
        }
        if(!temp.empty())
            ans.push_back(temp);
    }
    return ans;
}