#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Heap{
    
    int size = 1;
    int latestLevel = 1;    //tells the number of levels in the heap
    int lastEl = -1;
    int *arr;

    public:
    Heap(){
        cout<<"Construction!";
        arr = new int[size];
    }
    
    Heap(int s){
        if(!(s && (s & (s+1)))){
            //if s+1 is a power of 2
            size = s;
            latestLevel = log2(s+1);
        } else {
            latestLevel = log2(s+1)+1;
            size = pow(2,latestLevel) - 1;
            //using GP sum formula
        }
    }

    void insert(int el){
        if(lastEl == size-1){
            int newsize = size + pow(2,latestLevel);
            latestLevel++;
            int *T = new int[size];            
            for(int i=0; i<size; i++)
                T[i] = arr[i];
            delete[] arr;
            arr = T;      
            size = newsize;      
        }
        lastEl++;
        arr[lastEl] = el;
        int ind = lastEl;
        while(ind > 1){
            int parent = ind/2;
            if(arr[ind] > arr[parent])
                swap(arr[ind], arr[parent]);
            else
                break;
        }
    }

    void print(){
        for(int i=0; i<=lastEl; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Heap h1;
}