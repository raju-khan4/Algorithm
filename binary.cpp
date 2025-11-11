#include <iostream>
using namespace std;

int main() {
    int n, key;

    // Step 1: Input array size
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Step 2: Input array elements (must be sorted)
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Input the element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Step 4: Binary search process
    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;   // Find middle index

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;   // Search right half
        }
        else {
            high = mid - 1;  // Search left half
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
