//Queries on a Matrix

class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Q) {
        // Code here
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(int k=0; k<Q.size(); k++){
            for(int i=Q[k][0]; i<=Q[k][2]; i++){
            mat[i][Q[k][1]]++;
            
            if(Q[k][3]+1<n)
                mat[i][Q[k][3]+1]--;
            }
        }
        
        for(int i=0; i<n; i++)
            for(int j=1; j<n; j++)
                mat[i][j]+=mat[i][j-1];
        
        
        return mat;
    }
};