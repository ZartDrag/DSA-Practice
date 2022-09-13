#include<iostream>
#include<vector>

using namespace std;

void initArray(vector<int>& arr){
    cout<<"Enter size of array: ";
    int n; cin>>n;
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

void SelectionSort(vector<int>& arr, int i){

    if(i==arr.size()-1) return ;

    int min=i;
    for(int j=i+1; j<arr.size(); j++){
        if(arr[min]>arr[j]) min=j;
    }
    swap(arr[min],arr[i]);
    SelectionSort(arr, i+1);
}

int main(){
    vector<int> arr;
    initArray(arr);
    
    SelectionSort(arr,0);

    dispArray(arr);
    return 0;
}