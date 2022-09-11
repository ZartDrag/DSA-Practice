#include<iostream>

using namespace std;

bool Search(int arr[], int l, int h, int target){
    int mid=l+(h-l)/2;

    if(l>h) return false;
    if(arr[mid]==target) return true;
    if(arr[mid]<target) return Search(arr, l, mid-1, target);
    else return Search(arr, mid+1, h, target);
}

int main(){
    int arr[] = {1,2,3,4,5};
    
    cout<<Search(arr,0,5,3)<<endl<<Search(arr,0,5,9);
}