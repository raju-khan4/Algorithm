#include <iostream>
using namespace std;

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int temp[100];  // টেম্পোরারি অ্যারে (size বড় লাগলে বাড়াতে হবে)

    while (i <= mid && j <= h) {
        if (A[i] <= A[j]) {
            temp[k] = A[i];
            i++;
            k++;
        } else {
            temp[k] = A[j];
            j++;

            k++;
        }
        
    }
    if(i>mid)
    {
        while (j <= h) {   // Right side বাকি থাকলে
        temp[k] = A[j];
        j++;
        k++;
    }

    }
  else{
    while (i <= mid) {  // Left side বাকি থাকলে
        temp[k] = A[i];
        i++;
        k++;
    }
     }
    
    for (k = l; k <= h; k++) {
        A[k] = temp[k];
    }
}

void mergesort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[100];  // Fixed size array, maximum 100 element
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
       
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
    cout<<endl;
    
    }
    mergesort(A, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    
    return 0;
}
