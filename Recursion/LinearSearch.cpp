#include<iostream>

using namespace std;

bool Search(int arr[], int size, int target){
    if(size==0) return false;
    if(arr[0]==target) return true;
    return Search(arr+1,size-1,target);
}

int main(){
    int arr[] = {1,2,3,4,5};
    
    cout<<Search(arr,5,3)<<endl<<Search(arr,5,9);
}