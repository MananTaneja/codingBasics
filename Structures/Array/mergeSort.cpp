#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;


void merge(vector<int>& arr, int l, int m, int r) {
    
    int size1 = m - l + 1;
    int size2 = r - m;

    // Creating 2 temporary arrays to store data
    int left_array[size1];
    int right_array[size2];

    // Filling 2 temporary arrays 
    // First Array is filled from low -> size1 of parent array
    // Second array is filled from m + 1 -> size2 of parent array
    for(int i = 0; i < size1; i++) {
        left_array[i] = arr[l + i];
    }
    for(int i = 0; i < size2; i++) {
        right_array[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0; // Initial indices of left_array and right_array
    int k = l; // Initial index of merged  sub array

    // Checks condition where both the indices are in range
    // whenever is completed and the other is not the remaining elements are filled  later
    while(i < size1 && j < size2) {
        if (left_array[i] < right_array[j]) { // if left_array element is smaller then that is pushed in merged array and its index is incremented
            arr[k] = left_array[i];
            i++;
        }
        else { // else if they are equal or right_arr has the smaller element then that is pushed and its index is incremented 
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    // Now we just have to fill in the remaining elements 
    // remaining  elements of left or right array by checking with their respective sizes 
    while (i < size1) {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = right_array[j];
        j++;
        k++;
    }

} 

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int main() {

    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "The given array is: ";
    for(int x: arr) {
        cout << x << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, arr.size() -1);

    cout << "The sorted array is: ";
    for(int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}