#include<iostream>

using namespace std;

int Fibo(int n){
    n--;
    int *T= new int[n+1];
    T[0]=0; T[1]=1;

    for(int i=2; i<=n; i++)
      T[i]=T[i-1]+T[i-2];   

    return T[n];
}

int optimisedFibo(int n){
    int prev1=1, prev2=0;
    int curr;
    for(int i=2; i<n; i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }

    return curr;
}

int main(){
    cout<<"n: ";
    int n; cin>>n;
    cout<<optimisedFibo(n);
    
    return 0;
}