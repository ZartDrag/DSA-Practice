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

void SelectionSort(vector<int>& arr){

    for(int i=0; i<arr.size()-1; i++){
        int min=i;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j]<arr[min]) min=j;
        }
        swap(arr[i],arr[min]);
    }
}

int main(){
    vector<int> arr;
    initArray(arr);
    
    SelectionSort(arr);

    dispArray(arr);
    return 0;
}