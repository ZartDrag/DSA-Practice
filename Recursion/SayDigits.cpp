#include<iostream>
#include<string>

using namespace std;

void SayDigits(int n){
    string map[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    if(n==0) return ;
    SayDigits(n/10);
    cout<<map[n%10]<<" ";
    return ;
}

int main(){
    int x;
    cin>>x;
    SayDigits(x);
    return 0;
}