#include<iostream>
#include<vector>

using namespace std;

bool isSorted(int arr[], int size){

    if(size==0 || size==1) return true;

    if(arr[0]>arr[1]) return false;

    return isSorted(arr+1, size-1);
}

bool isSorted(vector<int> arr){
    if(arr.size()==0 || arr.size()==1) return true;

    if(arr[0]>arr[1]) return false;

    arr.erase(arr.begin());
    return isSorted(arr);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int arr2[] = {1,4,2,6,8};
    int arr3[] = {1,1,1,1,3};

    vector<int> arr4 = {1,2,3,4,5};
    vector<int> arr5 = {1,4,2,6,8};
    vector<int> arr6 = {1,1,1,1,3};

    cout<<isSorted(arr,5)<<endl<<isSorted(arr2,5)<<endl<<isSorted(arr3,5)<<endl;

    cout<<isSorted(arr4)<<endl<<isSorted(arr5)<<endl<<isSorted(arr6)<<endl;
    return 0;
}