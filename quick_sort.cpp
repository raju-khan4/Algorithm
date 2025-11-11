#include <iostream>
using namespace std;

// Partition function (Hoare scheme)
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    while (i < j)
    {
        while (A[i] <= pivot && i <= h - 1)
            i++;

        while (A[j] > pivot && j >= l + 1)
            j--;

        if (i < j)
            swap(A[i], A[j]);
    }

    swap(A[l], A[j]);
    return j;
}

// Quick Sort function
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = partition(A, l, h);
        quickSort(A, l, j - 1);
        quickSort(A, j + 1, h);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    quickSort(A, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}
