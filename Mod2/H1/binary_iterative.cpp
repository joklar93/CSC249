#include <iostream>
using namespace std;

int IterativeBinarySearch(int numbers[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (numbers[mid] < key)
            low = mid + 1;
        else if (numbers[mid] > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    int numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Enter a number to search: ";
    int key;
    cin >> key;

    int index = IterativeBinarySearch(numbers, size, key);
    if (index == -1)
        cout << key << " was not found." << endl;
    else
        cout << "Found " << key << " at index " << index << "." << endl;

    return 0;
}