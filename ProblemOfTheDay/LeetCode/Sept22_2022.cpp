//Reverse Words in a String III

class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        for(int i=0, start=0; i<s.length(); i++){
            
            if(s[i]==' '){
                
                int mid=((i-1)+start)/2;
                
                for(int j=start, k=0; j<=mid; j++,k++){
                    swap(s[j],s[i-k-1]);                    
                }
                start=i+1;
            }
        }
        s.pop_back();
        return s;
    }
};