#include <iostream>
using namespace std;

int main() {
    // Step 1: Declare and initialize an array
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Get the size of the array

    // Step 2: Use iteration to process the array
    int sum = 0;
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " "; // Print each element
        sum += numbers[i];         // Add element to sum
    }
    cout << endl;

    // Step 3: Display the result
    cout << "The sum of the elements is: " << sum << endl;

    return 0;
}