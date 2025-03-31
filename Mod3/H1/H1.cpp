#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main() {
   int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
      
   // Initialize a new Stack and add numbers
   Stack numStack;
   for (int number : numbers) {
      numStack.Push(number);
   }

   // Output stack
   cout << "Stack after initial pushes:   ";
   numStack.Print(cout);
      
   // Pop and print, push 99 and print, pop and print again
   numStack.Pop();
   cout << "Stack after first pop:        ";
   numStack.Print(cout);
   numStack.Push(99);
   cout << "Stack after pushing 99:       ";
   numStack.Print(cout);
   numStack.Pop();
   cout << "Stack after second pop:       ";
   numStack.Print(cout);
      
   // Print a blank line before the Queue demo
   cout << endl;
      
   // Initialize a new Queue and add numbers
   Queue numQueue;
   for (int number : numbers) {
       numQueue.Enqueue(number);
   }

   // Output queue
   cout << "Queue after initial enqueues: ";
   numQueue.Print(cout);
      
   // Dequeue 83 and print
   numQueue.Dequeue();
   cout << "Queue after first dequeue:    ";
   numQueue.Print(cout);
      
   // Enqueue 99 and print
   numQueue.Enqueue(99);
   cout << "Queue after enqueueing 99:    ";
   numQueue.Print(cout);
      
   // Dequeue 4 and print
   numQueue.Dequeue();
   cout << "Queue after second dequeue:   ";
   numQueue.Print(cout);
}