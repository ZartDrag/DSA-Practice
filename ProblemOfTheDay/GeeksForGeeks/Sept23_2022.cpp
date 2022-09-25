//Geek and Number String


class Solution{
public:
    int minLength(string s, int n) {
        // code here
        stack<int> stk;
        int pair[10]={9,2,1,4,3,6,5,8,7,0};
        
        for(int i=0; i<n; i++){
            if(stk.empty()) 
                stk.push(s[i]-'0');
            else if(stk.top()==pair[s[i]-'0'])
                stk.pop();
            else
                stk.push(s[i]-'0');
        }
        return stk.size();
    } 
};
