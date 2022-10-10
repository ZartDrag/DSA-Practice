#include <iostream>
#include <vector>

using namespace std;

int solution(string files) {
    // Write solution here
    vector<char> vec;
    int count=0;
    for( char ch:files ){
        if(vec.empty()) vec.push_back(ch);
        else{
            bool found=false;
            for(int i=0; i<vec.size(); i++){
                if(vec[i]==ch){
                    count+=2;
                    vec.erase(vec.begin()+i);
                    found=true;
                    break;
                }                
            }
            if(!found) vec.push_back(ch);
        }
    }
    
    if(vec.empty()) return count;
    
    return count+1;
}


int main() {
     string files="abccccdd";
    //  cin>>files;
     cout<<solution(files);
     return 0;
}