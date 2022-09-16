#include <iostream>
#include <vector>

using namespace std;

void initArray(vector<int> &arr)
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        arr.push_back(t);
    }
}

void InsertionSort(vector<int> &arr, int i)
{
    if (i == arr.size())
        return;

    int j = i, temp = arr[i];

    while (j--)
    {
        if (arr[j] > temp)
            arr[j + 1] = arr[j];
        else
            break;
    }
    arr[j + 1] = temp;
    InsertionSort(arr, i + 1);
}

void dispArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4, 5, 0};
    // initArray(arr);

    InsertionSort(arr, 1);

    dispArray(arr);
    return 0;
}