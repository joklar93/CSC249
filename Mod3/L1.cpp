#include <iostream>
using namespace std;

class ArrayStack {
    private:
       int allocationSize;
       int* array;
       int length;
       int maxLength;
       
       void Resize() {
            // Allocate new array and copy existing items
            int newSize = allocationSize * 2;
            int* newArray = new int[newSize];
            for (int i = 0; i < length; i++) {
                newArray[i] = array[i];
            }
            
            // Free old array and assign new
            delete[] array;
            array = newArray;
            allocationSize = newSize;
       }
           
    public:
       ArrayStack(int optionalMaxLength = -1) {
          allocationSize = 1;
          array = new int[allocationSize];
          length = 0;
          maxLength = optionalMaxLength;
       }
        
       virtual ~ArrayStack() {
          delete[] array;
       }
       
       int GetLength() const {
          return length;
       }
        
       int GetMaxLength() const {
          return maxLength;
       }
        
       bool Push(int item) {
          // If at max length, return false
          if (length == maxLength) {
             return false;
          }
          
          // Resize if length equals allocation size
          if (length == allocationSize) {
             Resize();
          }
            
          // Push the item and return true
          array[length] = item;
          length++;
          return true;
       }
        
       int Pop() {
          length--;
          return array[length];
       }

        void PrintStack() {
            cout << "Stack items (top to bottom): ";
            for (int i = length - 1; i >= 0; i--) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    };

int main() {
    // Create a stack with a maximum length of 5
    ArrayStack stack(5);

    // Print initial stack information
    cout << "Initial stack length: " << stack.GetLength() << endl;
    cout << "Max stack length: " << stack.GetMaxLength() << endl;

    // Push some elements onto the stack
    cout << "\nPushing values onto the stack...\n";
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    
    // Try pushing beyond max limit
    if (!stack.Push(6)) {
        cout << "Stack is full! Cannot push 6.\n";
    }
    
    // Print updated stack length
    cout << "\nStack length after pushes: " << stack.GetLength() << endl;
    
    // Pop elements and display them
    cout << "\nPopping values from the stack...\n";
    cout << "Popped: " << stack.Pop() << endl;
    cout << "Popped: " << stack.Pop() << endl;
    cout << "Popped: " << stack.Pop() << endl;
    
    // Print stack length after popping
    cout << "\nStack length after pops: " << stack.GetLength() << endl;
    
    // Push again to check resizing behavior
    cout << "\nPushing more values onto the stack...\n";
    stack.Push(6);
    stack.Push(7);
    
    // Print final stack length
    cout << "Final stack length: " << stack.GetLength() << endl;
    
    stack.PrintStack();

    return 0;
}