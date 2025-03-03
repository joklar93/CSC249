#include <iostream>
using namespace std;

int BinarySearch(int numbers[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (numbers[mid] < key)
        return BinarySearch(numbers, mid + 1, high, key);
    else if (numbers[mid] > key)
        return BinarySearch(numbers, low, mid - 1, key);
    return mid;
}

int main() {
    int numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Enter a number to search: ";
    int key;
    cin >> key;

    int index = BinarySearch(numbers, 0, size - 1, key);
    if (index == -1)
        cout << key << " was not found." << endl;
    else
        cout << "Found " << key << " at index " << index << "." << endl;

    return 0;
}