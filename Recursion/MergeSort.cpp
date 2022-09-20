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

void dispArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(vector<int> &arr, int l, int h)
{
    vector<int> firstArr, secondArr;
    int mid = l + (h - l) / 2;

    for (int i = l; i <= mid; i++)
        firstArr.push_back(arr[i]);
    for (int i = mid + 1; i <= h; i++)
        secondArr.push_back(arr[i]);

    int fi = 0, si = 0, i = l;
    while (fi < firstArr.size() && si < secondArr.size())
    {
        if (firstArr[fi] < secondArr[si])
            arr[i++] = firstArr[fi++];
        else
            arr[i++] = secondArr[si++];
    }

    while (fi < firstArr.size())
    {
        arr[i++] = firstArr[fi++];
    }

    while (si < secondArr.size())
    {
        arr[i++] = secondArr[si++];
    }
    dispArray(arr);
}

void altMerge(vector<int> &arr, int l, int h)
{
    int mid = l + (h - l) / 2;

    for (int i = mid + 1; i <= h; i++)
    {
        int j, temp = arr[i];
        for (j = i - 1; j >= l; j--)
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

void MergeSort(vector<int> &arr, int l, int h)
{

    if (l >= h)
        return;

    int mid = l + (h - l) / 2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, h);

    altMerge(arr, l, h);
}

int main()
{
    vector<int> arr = {1, 3, 9, 2, 7, 2, 6};
    // initArray(arr);
    MergeSort(arr, 0, arr.size() - 1);
    dispArray(arr);
    return 0;
}