//Rat in a maze problem - 1

class Solution{
    void solve(vector<vector<int>> m, int n, int i, int j, vector<vector<int>> visited, vector<string> &ans, string curr){
        if(i==n-1 && j==n-1){
            ans.push_back(curr);
            return;
        }
        visited[i][j]=1;
        if(j+1<n && m[i][j+1]==1 && visited[i][j+1]==0){
            solve(m,n,i,j+1,visited,ans,curr+"R");
        }
        if(i+1<n && m[i+1][j]==1 && visited[i+1][j]==0){
            solve(m,n,i+1,j,visited,ans,curr+"D");
        }
        if(j-1>=0 && m[i][j-1]==1 && visited[i][j-1]==0){
            solve(m,n,i,j-1,visited,ans,curr+"L");
        }
        if(i-1>=0 && m[i-1][j]==1 && visited[i-1][j]==0){
            solve(m,n,i-1,j,visited,ans,curr+"U");
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return {"-1"};
            
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n,0));
        solve(m,n,0,0,visited,ans,"");
        return ans;
    }
};
