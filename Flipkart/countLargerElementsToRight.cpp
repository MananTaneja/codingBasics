#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &count, vector<pair<int, int>> &numsIndices, int l, int m, int r)
{
    vector<pair<int, int>> temp(r - l + 1);

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
        if (numsIndices[i].first >= numsIndices[j].first)
        { // use <= for smaller elements to right
            temp[k] = numsIndices[j];
            k++;
            j++;
        }
        else
        {
            count[numsIndices[i].second] += r - j + 1;
            temp[k] = numsIndices[i];
            k++;
            i++;
        }
    }

    while (i <= m)
    {
        temp[k] = numsIndices[i];
        k++;
        i++;
    }

    while (j <= r)
    {
        temp[k] = numsIndices[j];
        k++;
        j++;
    }

    for (int i = l; i <= r; i++)
    {
        numsIndices[i] = temp[i - l];
    }
}

void mergeSort(vector<int> &count, vector<pair<int, int>> &numsIndices, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(count, numsIndices, l, m);
        mergeSort(count, numsIndices, m + 1, r);

        merge(count, numsIndices, l, m, r);
    }
}

vector<int> countLargerElements(vector<int> &nums)
{
    vector<pair<int, int>> numsIndices;
    const int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        numsIndices.push_back({nums[i], i});
    }
    vector<int> count(n, 0);

    mergeSort(count, numsIndices, 0, n - 1);

    return count;
}

int main()
{
    vector<int> nums = {3, 7, 1, 5, 9, 2};
    // vector<int> nums = {5, 2, 6, 1};
    cout << "Input: ";
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
    cout << "Result: "
         << " ";
    vector<int> res = countLargerElements(nums);
    for (int n : res)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}