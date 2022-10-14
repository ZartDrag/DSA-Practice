#include<iostream> 
#include<cstring>
using namespace std; 

void reversal(string & str, int i, int j){    
    if(i>=j) return ;
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    reversal(str,++i,--j);
}


int main() 
 { 
    string str;
    cout<<"Enter the string : ";
    getline(cin,str);
    reversal(str,0,(str.length()-1)); 
    cout << "Reversed string is: "<<str;
    return 0; 
}
