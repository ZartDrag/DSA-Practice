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

void BubbleSort(vector<int>& arr, int i){
    if(i==arr.size()) return ;

    for(int j=0; j<arr.size()-i; j++)
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);

    BubbleSort(arr, i+1);
}

int main(){    
    vector<int> arr;
    initArray(arr);
    
    BubbleSort(arr, 1);

    dispArray(arr);
    return 0;
}