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

int partition(vector<int> &arr, int l, int h)
{
    int p = l;

    for (int i = l + 1; i <= h; i++)
        if (arr[i] <= arr[l])
            p++;

    swap(arr[p], arr[l]);

    int i = l, j = h;
    while (i < p && j > p)
    {
        while (arr[i] <= arr[p])
            i++;

        while (arr[p] < arr[j])
            j--;

        if (i < p && j > p)
            swap(arr[i++], arr[j--]);
    }

    dispArray(arr);
    return p;
}

void QuickSort(vector<int> &arr, int l, int h)
{
    if (l >= h)
        return;

    int p = partition(arr, l, h);

    QuickSort(arr, l, p - 1);
    QuickSort(arr, p + 1, h);
}

int main()
{
    vector<int> arr = {6, 6, -6, -2, -4, -6, 2, -6 };
    // initArray(arr);

    QuickSort(arr, 0, arr.size() - 1);

    dispArray(arr);
    return 0;
}