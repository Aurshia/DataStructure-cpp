#include <iostream>
using namespace std;

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int i = left;      // start of left half
    int j = mid + 1;   // start of right half
    int k = 0;

    int temp[100];     // temporary array (easy way)

    // Compare and merge
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left half
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right half
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        int mid = (left + right) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
    }
}

int main() {

    int arr[] = {5, 2, 9, 1, 6};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
