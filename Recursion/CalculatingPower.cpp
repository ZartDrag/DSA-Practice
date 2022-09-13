#include<iostream>

using namespace std;

int power(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int odd = b%2?a:1, p=power(a,b/2);
    return odd * p * p;
}

int main(){
    cout<<"Enter 2 numbers: ";
    int a,b;
    cin>>a>>b;
    cout<<power(a,b);
    return 0;
}