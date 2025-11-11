#include <iostream>
using namespace std;

// Function to find factorial using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;   // Base case
    } else {
        return n * factorial(n - 1); // Recursive call
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial of " << n << " = " << factorial(n) << endl;

    return 0;
}
