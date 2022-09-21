//744. Find Smallest Letter Greater Than Target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0, h=letters.size()-1;
        int res=letters[0];
        
        cout<<("z">"a");
        
        while(l<=h){
            int mid = l+(h-l)/2;
            
            if(letters[mid]>target){
                res=letters[mid];
                h=mid-1;
            } else 
                l=mid+1;
        }
        
        return res;
        
    }
};