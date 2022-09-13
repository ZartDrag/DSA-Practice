#include<iostream>
#include<string>

using namespace std;

bool Pallin(string str, int i){
    int j=str.length()-1-i;
    if(i>j) return true;
    if(str[i]==str[j]) return Pallin(str,i+1);
    else return false;
}

int main(){
    cout<<"Enter a String: ";
    string str;
    cin>>str;
    cout<<Pallin(str, 0);
    return 0;
}