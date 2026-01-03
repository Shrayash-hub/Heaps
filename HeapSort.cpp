#include <bits/stdc++.h>
using namespace std;

// Heapify function (max-heap)
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);   // heapify affected subtree
    }
}

// Heap Sort
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Build Max Heap  (O(n))
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // move max to end
        heapify(arr, i, 0);     // heapify reduced heap
    }
}

int main() {
    vector<int> arr = {10, 20, 5, 6, 1, 8, 9, 4};

    heapSort(arr);

    cout << "Sorted Array: ";
    for(int x : arr) cout << x << " ";
}
