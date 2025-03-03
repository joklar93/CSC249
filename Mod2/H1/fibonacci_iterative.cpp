#include <iostream>
using namespace std;

int IterativeFibonacci(int termIndex) {
    if (termIndex == 0)
        return 0;
    else if (termIndex == 1)
        return 1;

    int prev = 0, curr = 1, next;
    for (int i = 2; i <= termIndex; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;
    cout << "Enter Fibonacci term index: ";
    cin >> n;

    cout << "Fibonacci number at index " << n << " is " << IterativeFibonacci(n) << endl;
    return 0;
}