#include<bits/stdc++.h>

using namespace std;

class Compare{
    public:

    bool operator()(int *a, int *b){
        return *a > *b;
    }
};

int main()
{
    int *a = new int[6];

    for (int i = 0; i < 6; i++)
        cout << a[i] << endl;

    return 0;
}