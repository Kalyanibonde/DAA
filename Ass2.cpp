#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Function declarations
void mergeSort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random array of 200 elements
    vector<int> arr1(200);
    for (int &num : arr1) {
        num = rand() % 1000; // Limit the range to 0-999 for better readability
    }

    // Creating a copy of the initial array for quick sort
    vector<int> arr2 = arr1;

    // Printing the original array (optional)
    cout << "Original array:\n";
    for (int i = 0; i < 20; i++) { // Print only the first 20 elements
        cout << arr1[i] << " ";
    }
    cout << "... (truncated)\n\n";

    // Measuring time for merge sort
    auto start_merge = high_resolution_clock::now();
    mergeSort(arr1, 0, arr1.size() - 1);
    auto stop_merge = high_resolution_clock::now();
    duration<double> duration_merge = stop_merge - start_merge;

    // Printing the sorted array after merge sort
    cout << "Sorted array using Merge Sort:\n";
    for (int i = 0; i < 20; i++) { // Print only the first 20 elements
        cout << arr1[i] << " ";
    }
    cout << "... (truncated)\n";
    cout << "Time taken by Merge Sort: " << duration_merge.count() << " seconds\n\n";

    // Measuring time for quick sort
    auto start_quick = high_resolution_clock::now();
    quickSort(arr2, 0, arr2.size() - 1);
    auto stop_quick = high_resolution_clock::now();
    duration<double> duration_quick = stop_quick - start_quick;

    // Printing the sorted array after quick sort
    cout << "Sorted array using Quick Sort:\n";
    for (int i = 0; i < 20; i++) { // Print only the first 20 elements
        cout << arr2[i] << " ";
    }
    cout << "... (truncated)\n";
    cout << "Time taken by Quick Sort: " << duration_quick.count() << " seconds\n";

    return 0;
}

// Merge Sort implementation
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Finding the midpoint of the array
        int mid = left + (right - left) / 2;

        // Recursively sorting the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merging the two halves
        merge(arr, left, mid, right);
    }
}

// Merge function to combine two sorted halves
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left half
    int n2 = right - mid;    // Size of the right half

    // Temporary arrays to hold the two halves
    vector<int> L(n1), R(n2);

    // Copying data to the temporary arrays
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Initial indices of the temporary arrays
    int i = 0, j = 0;
    // Initial index of the merged subarray
    int k = left;

    // Merging the temporary arrays back into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copying any remaining elements of the left half
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copying any remaining elements of the right half
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Quick Sort implementation
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning the array and getting the pivot index
        int pi = partition(arr, low, high);

        // Recursively sorting the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function for quick sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1);     // Index of the smaller element

    // Reordering the array based on the pivot element
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
