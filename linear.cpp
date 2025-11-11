#include <iostream>
using namespace std;

int main() {
    int n, key;

    // Step 1: Input array size
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Step 2: Input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Input the element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Step 4: Linear search process
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;  // stop after finding the element
        }
    }

    // Step 5: If not found
    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
