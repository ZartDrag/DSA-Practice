//IPL 2021 - Match Day 2

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque<int> que;
        que.push_front(0);
        for(int i=1; i<k; i++){
            while(!que.empty() && arr[que.back()]<=arr[i]) que.pop_back();
            que.push_back(arr[i]);
        }
        ans.push_back(arr[que.front()]);
        for(int i=0, j=i+k; j<n; i++, j++){
            if(i==que.front()) que.pop_front();
            while(!que.empty() && arr[que.back()]<=arr[j]) que.pop_back();
            que.push_back(arr[j]);
            ans.push_back(arr[que.front()]);
        }
    
        return ans;
    }