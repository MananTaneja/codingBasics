#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr)
{
    cout << "The Array content is: ";
    for (int num : arr)
    {
        cout << num << ", ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &arr)
{
    int t = arr.size();
    int count = 1;
    while (t--)
    {
        vector<int> temp = arr;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            cout << count++ << " ";
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        if (temp == arr)
            break;
    }
}

int main()
{
    vector<int> arr = {9, 5, 7, 4, 67, 88};

    printArray(arr);

    bubbleSort(arr);

    printArray(arr);

    return 0;
}