//338. Counting Bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec;
        for(int i=0; i<=n; i++){
            int t = i;
            int cnt = 0;
            while(t){
                t = t & (t-1);  
                cnt++;
            }
            vec.push_back(cnt);
        }
        
        return vec;
    }
};