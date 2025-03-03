#include <iostream>
using namespace std;

int FibonacciNumber(int termIndex) {
    if (termIndex == 0)
        return 0;
    else if (termIndex == 1)
        return 1;
    else
        return FibonacciNumber(termIndex - 1) + FibonacciNumber(termIndex - 2);
}

int main() {
    int n;
    cout << "Enter Fibonacci term index: ";
    cin >> n;

    cout << "Fibonacci number at index " << n << " is " << FibonacciNumber(n) << endl;
    return 0;
}