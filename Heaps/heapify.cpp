#include<iostream>>

using namespace std;

void heapify(int arr[], int i, int n){
    int lar = i; 
    int left = lar * 2;
    int right = left + 1;

    if(left < n && arr[left] > arr[lar])
        lar = left;
    

    if(right < n && arr[right] > arr[lar])
        lar = right;
    

    if(lar != i){
        swap(arr[i], arr[lar]);
        heapify(arr, lar, n);
    }
}

int main(){
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--)
        heapify(arr, i, n);
    

    for(int i : arr)
        cout<<i<<" ";

    return 0;
}