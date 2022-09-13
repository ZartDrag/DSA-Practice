#include<iostream>
#include<vector>

using namespace std;

void initArray(vector<int>& arr, int& n){
    cout<<"Enter size of array: ";
    cin>>n;
    int t;
    for(int i=0; i<n; i++){ 
        cin>>t;
        arr.push_back(t);
    }
}

void dispArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void BubbleSort(vector<int>& arr){
    for(int i=1; i<arr.size(); i++)
        for(int j=0; j<arr.size()-i; j++)
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
}

int main(){
    
    int n; 
    vector<int> arr;
    initArray(arr,n);
    // dispArray(arr); 
    BubbleSort(arr);    
    dispArray(arr);    

    return 0;
}