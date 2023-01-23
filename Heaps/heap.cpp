#include<iostream>

using namespace std;

class Heap{
    int size;
    int arr[100];

    public:
    Heap(){
        size = 0;
        arr[0] = -1;
    }
    
    bool insert(int val){
        if(size == 100)
            return false;

        size++;
        arr[size] = val;

        int ind = size;
        while(ind > 1){
            int par = ind / 2; 
                //the parent would always be at ind/2 index

            if(arr[ind] > arr[par])
                swap(arr[ind], arr[par]);
            else
                return true;
            
            ind = par;
        } 

        return true;
    }

    bool deleteFromHeap(){
        if(size==0)
            return false;

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){
            int left = i*2, right = i*2+1;

            if(left <= size && arr[i] < arr[left] && arr[left] > arr[right]){
                swap(arr[left], arr[i]);
                i = left;
            } else if(right <= size && arr[i] < arr[right]){
                swap(arr[right], arr[i]);
                i = right;
            } else 
                return true;
        }

        return true;
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Heap h;
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(52);
    h.print();
    h.deleteFromHeap();
    h.print();
}