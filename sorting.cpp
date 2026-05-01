#include<iostream>
using namespace std;

//selection sort
void selectionsort(int arr[] , int size ){
    for(int i = 0 ; i < size-1 ; i++){
        int min = i ;
        for(int j = i ; j< size-1 ; j++){
            if(arr[min] > arr[j+1]){
                min = j+1;
            }
            swap(arr[min] , arr[i]);
        }
    }
}

//bubblesort
void bubblesort(int arr[] , int size ){
    for(int i = 0 ; i < size-1 ; i++){
        for(int j = 1  ; j< size-i ; j++){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1] , arr[j]);
            }  
        }
    }
}

//merge sort
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







//| Question hint    | Best algorithm     |
//| ---------------- | ------------------ |
//| Already sorted   | Bubble (optimized) |
//| Nearly sorted    | Bubble (optimized) |
//| Minimum swaps    | Selection          |
//| Stability needed | Bubble             |
//| Small data       | Bubble             |
//| No hint given    | Bubble             |



//linear search  (use when array is unsorted)
int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i;  // found
    }
    return -1;  // not found
}


//binary search(used when array is sorted)
int binarysearch(int arr[] , int l , int r , int value){
    if(l<=r){
        int mid = (l+r)/2;
        if(arr[mid] == value){
            return mid;
        }
        
        if(value < arr[mid]){ //value smaller so move to left 
            return binarysearch(arr , l , mid-1 , value);
        }
        else{
            return binarysearch(arr , mid+1 , r , value);
        }
        
    }
}

