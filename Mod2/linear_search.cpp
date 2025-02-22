#include <iostream>
using namespace std;

int LinearSearch(float* numbers, int numbersSize, float key) {
   for (int i = 0; i < numbersSize; i++) {
      if (numbers[i] == key) {
         return i;
      }
   }
   return -1; // not found
}

int main() {
   float numbers[] = { 1.337, 3.4, 6.9, 4.04, 7.3, 10.4, 11.5, 32.6, 45., 87.8 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
   cout << "NUMBERS: [" << numbers[0];
   for (int i = 1; i < numbersSize; i++) {
      cout << ", " << numbers[i];
   }
   cout << "]" << endl;
      
   // Prompt for an float to search for
   cout << "Enter an float value: ";
   float key = 0;
   cin >> key;

   int keyIndex = LinearSearch(numbers, numbersSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }
}