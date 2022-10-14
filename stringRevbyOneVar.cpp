#include<iostream> 
#include<string>
using namespace std; 

void stringRev(string &str,int i){
    if(i == (str.length()/2)) return ;
    char temp = str[i];
    str[i] = str[(str.length()-1)-i];
    str[(str.length()-1)-i] = temp;
    stringRev(str,++i);
}

int main() 
 { 
    string str;
    cout<< "Enter the string : ";
    getline(cin,str);
     
    stringRev(str,0);

    cout<<"\n the reversed string is " <<str;
    return 0; 
}
