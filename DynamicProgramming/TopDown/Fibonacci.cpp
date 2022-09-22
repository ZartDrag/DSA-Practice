#include<iostream>

using namespace std;

int *T;

int Fibo(int n){
    if(n==0 || n==1) return n;
    
    if(T[n]!=-1) return T[n];

    return T[n]=Fibo(n-1) + Fibo(n-2);
}

int main(){
    cout<<"n: ";
    int n; cin>>n;

    T= new int[n+1];
    for(int i=0; i<=n; i++) T[i]=-1;
    
    cout<<Fibo(n-1);
    return 0;
}