#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many terms you want: ";
    cin >> n;

    int a = 0, b = 1, next;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; i++) {
        cout << a << " ";     // print current term
        next = a + b;         // calculate next term
        a = b;                // move forward
        b = next;
    }

    cout << endl;
    return 0;
}
