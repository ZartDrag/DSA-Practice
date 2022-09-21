//17. Letter Combinations of a Phone Number

class Solution {
    void solve(string digits, int index, vector<string> &ans, string output, vector<string> mapping){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        
        int num = digits[index] - '0';
        for(int i=0; i<mapping[num].length(); i++){
            solve(digits, index+1, ans, output+mapping[num][i], mapping);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> mapping={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.length()==0) return ans;        
        
        solve(digits, 0, ans, "", mapping);
        
        return ans;        
    }
};