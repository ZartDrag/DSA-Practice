#include <bits/stdc++.h>
using namespace std;

bool isSorted(int P[], int N){
    for(int i=1; i<N; i++)
        if(P[i-1]>P[i]) return false;
    
    return true;
}

void reverse(int P[], int N, int str, int end){

    if(str>=end) return;
    
    for(int i=str, j=end; i<=j; i++, j--){
        swap(P[i],P[j]);
    }
}

void findSubStrings(int N, int M, int P[], vector<pair<int,int>> &subs)
{
    int sum=0, str=0;

    for(int i=0; i<N; i++){

        if(sum==0 && P[i]<=M){
            str=i;
            sum+=P[i];
        } else if(sum+P[i]>M){
            if(str!=i-1) 
                subs.push_back(make_pair(str,i-1));
            sum-=P[str];
            str++;
            i--;
        }
    }
}

int solution(int N, int M, int P[])
{
    // Write solution here
    if(isSorted(P, N)) return 1;
    vector<pair<int,int>> subs;
    findSubStrings(N, M, P, subs);

    for( pair<int,int> a:subs ){
        cout<<a.first<<" "<<a.second<<endl;
        reverse(P, N, a.first, a.second);
    }


    

    // int sum=0, str=0;
    // vector<int> arr;
    // int i;
    // for(i=0; i<N; i++){
    //     if(sum+P[i]>M){
    //         reverse(P, N, str, i-1, arr);
    //         if(isSorted(P, N)) return 1;
    //     } else {
    //         if(arr.empty()) str=i;
    //         arr.push_back(P[i]);
    //         sum+=P[i];
    //     }
    // }

    // if(!arr.empty()) reverse(P, N, str, i-1, arr);
    // if(isSorted(P, N)) return 1;
	return 0;
}

int main() {
    int n,m;
    cin>>n>>m;
    int P[n];
    for(int i=0;i<n;i++){
        scanf("%d", &P[i]);
    }
	cout<<solution(n,m,P)<<endl;
	return 0;
}
