// CSC249
// M2HW1 - Gold Attempt
// Binary Search and Guessing Game
// 4/13/25

#include <iostream>
using namespace std;

int BinarySearch(int* numbers, int numbersSize, int key) 
{
    int low = 0;
    int high = numbersSize - 1;
    
    while (high >= low) {
       int mid = (high + low) / 2;
       if (numbers[mid] < key) {
          low = mid + 1;
       }
       else if (numbers[mid] > key) {
          high = mid - 1;
       }
       else {
          return mid;
       }
    }
    
    return -1; 
}

// Binary search demo function
void binarySearchDemo() {
    int numbersSize;
    int key;
    
    cout << "Enter the size of the array: ";
    cin >> numbersSize;
    
    int* numbers = new int[numbersSize];
    
    cout << "Enter " << numbersSize << " numbers in ascending order:" << endl;
    for (int i = 0; i < numbersSize; i++) {
        cin >> numbers[i];

        if (i > 0 && numbers[i] < numbers[i-1]) {
            cout << "Error: Numbers must be in ascending order." << endl;
            cout << "Please restart the binary search demo." << endl;
            delete[] numbers;
            return;
        }
    }
    
    cout << "Enter the number to search for: ";
    cin >> key;
    
    int position = BinarySearch(numbers, numbersSize, key);
    
    if (position == -1) {
        cout << key << " was not found in the array." << endl;
    } else {
        cout << key << " was found at index " << position << "." << endl;
    }
    
    delete[] numbers;
}


void guessingGame() {
    int low = 0;
    int high = 99;
    int mid;
    char response;
    int attempts = 0;
    const int MAX_ATTEMPTS = 5;
    bool foundNumber = false;
    
    cout << "Think of a number between 0 and 99." << endl;
    cout << "I will try to guess it in 5 attempts or fewer." << endl;
    cout << "Enter '<' if your number is lower, '>' if higher, or '=' if I guessed correctly." << endl;
    
 
    while (attempts < MAX_ATTEMPTS && !foundNumber && high >= low) {
        mid = (high + low) / 2;
        attempts++;
        
        cout << "Attempt " << attempts << ": Is your number " << mid << "? ";
        cin >> response;
        
        if (response == '<') {
            high = mid - 1;
        }
        else if (response == '>') {
            low = mid + 1;
        }
        else if (response == '=') {
            foundNumber = true;
        }
        else {
            cout << "Invalid input. Please enter '<', '>', or '='." << endl;
            attempts--; 
        }
    }
    
    if (foundNumber) {
        cout << "Great! I guessed your number (" << mid << ") in " << attempts << " attempts." << endl;
    }
    else {
        cout << "I couldn't guess your number in " << MAX_ATTEMPTS << " attempts." << endl;
        if (high >= low) {
            cout << "Your number must be between " << low << " and " << high << "." << endl;
        }
    }
}

void displayMenu() {
    cout << "\n========== BINARY SEARCH MENU ==========" << endl;
    cout << "1. Binary Search Demo" << endl;
    cout << "2. Binary Guess the Number Game" << endl;
    cout << "3. Quit" << endl;
    cout << "=========================================" << endl;
    cout << "Enter your choice (1-3): ";
}

int main() 
{
    int choice;
    bool exitProgram = false;
    
    while (!exitProgram) {
        displayMenu();
        
        // Check if the input is valid
        if (!(cin >> choice)) {
            // Clear the error flags
            cin.clear();
            // Discard the input buffer
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        cin.ignore(10000, '\n');
        
        switch (choice) {
            case 1:
                cout << "\n--- Binary Search Demo ---" << endl;
                binarySearchDemo();
                break;
                
            case 2:
                cout << "\n--- Binary Guess the Number Game ---" << endl;
                guessingGame();
                break;
                
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                exitProgram = true;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                break;
        }
    }
    
    return 0;
}