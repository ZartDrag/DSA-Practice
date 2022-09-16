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

void InsertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i;
        while (j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

void dispArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> arr;
    initArray(arr);

    InsertionSort(arr);

    dispArray(arr);
    return 0;
}