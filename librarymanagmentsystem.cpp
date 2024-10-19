#include <iostream>
#include <vector>
using namespace std;

int optimized_bubble_sort(vector<int> arr, bool ascending) {
    int swaps = 0;
    int n = arr.size();
    bool swapped; 

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                ++swaps;
                swapped = true; 
            }
        }
        
        if (!swapped) {
            break;
        }
    }
    return swaps;
}

int min_swaps(vector<int>& arr) {

    int asc_swaps = optimized_bubble_sort(arr, true);
    int desc_swaps = optimized_bubble_sort(arr, false);

    return min(asc_swaps, desc_swaps);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << min_swaps(arr) << endl;
    
    return 0;
}