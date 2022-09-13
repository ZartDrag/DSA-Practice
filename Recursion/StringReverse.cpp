#include<iostream>
#include<string>

using namespace std;

string StrRev(string str, int i){
    int j=str.length()-i-1;

    if(i>j) return str;

    char c=str[i];
    str[i]=str[j];
    str[j]=c;

    return StrRev(str, i+1);
}

int main(){
    cout<<"Enter a String: ";
    string str;
    cin>>str;
    cout<<StrRev(str, 0);
    return 0;
}