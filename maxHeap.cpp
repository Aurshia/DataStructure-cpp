#include<iostream>
using namespace std;
class maxHeap{
public:    
    int *h;
    int maxSize;
    int n;
    maxHeap(int *arr , int size , int sz){
        h = arr;
        maxSize = size;
        n = sz;
    }
    maxHeap(int mxsz){
        maxSize = mxsz;
        h = new int[maxSize + 1];
        n = 0;
    }
    void insert(int x){
        if(n == maxSize){
            cout<<"heap iw s full";
            return;
        }
        n++;
        int i ;
        for(i = n ; i > 1 ; i = i/2){
            if(x <= h[i/2]){
                break;
            }
            h[i] = h[i/2];
  
        }
        h[i] = x;
    }
    void print(){
        for(int i = 1 ; i <= n ; i++){
            cout<<h[i] <<" ";
        }
        cout<<endl;
    }
    int deletemax(){
        int root = h[1];
        h[1] = h[n];
        n--;
        heapify(1);
        return root;
    }
    void heapify(int i){
        int largest = i;
        int l = 2 * i;
        int r = 2 * i + 1;
        if(l <= n && h[l] > h[largest]){
            largest = l;
        }
        if(r <= n && h[l] > h[largest]){
            largest = r;
        }    
        if(largest != i){
            swap(h[i] , h[largest]);
            heapify(largest);
        }
    }
    void buildtree(){
        for(int i = n/2 ; i > 0 ; i-- ){
            heapify(i);
        }
    }
    bool isMaxHeap(int h[], int n) { // this is checking if the array is max heap or not
    for (int i = 1; i <= n / 2; i++) {
        if (2*i <= n && h[i] < h[2*i])
            return false;
        if (2*i + 1 <= n && h[i] < h[2*i + 1])
            return false;
    }
    return true;
}

};
int main(){
    cout<<"------------------------------"<<endl;
    int arr[] = {0, 65, 31, 32, 26, 21, 19, 68, 13, 24, 15, 14, 16, 5, 70, 12};
    int arr_sz = sizeof(arr)/sizeof(int);
    cout<<"Size of array: "<<arr_sz<<endl;
    maxHeap h2(arr, arr_sz, arr_sz-1);
    cout<<"Before heap: "<<endl;
    h2.print();
    h2.buildtree();
    cout<<"After Heap: "<<endl;
    h2.print();
    return 0;
}