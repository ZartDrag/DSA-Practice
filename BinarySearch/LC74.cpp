//74. Search a 2D Matrix
class Solution {
    
    int findPos(vector<vector<int>> matrix, int i){
        int row=matrix[0].size();
        
        return matrix[i/row][i%row];
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int l=0, h=matrix.size()*matrix[0].size()-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(target>findPos(matrix,mid)){
                l=mid+1;
            } else if(target<findPos(matrix,mid)){
                h=mid-1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};