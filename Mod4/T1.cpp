#include <iostream>
using namespace std;

// CSC 249
// M2LAB1 - Global Maximum
// James Reynolds
// 3/31/25

int main2() {
    // problem
    int a, b, c;

    // the problem
    // given three integers, a, b, c,
    // determine their order

    cout << "Enter three integers seperated by spaces" << endl;
    cin >> a >> b >> c;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;

    // print which one is the smallest
    // && = logical AND, & = bitwise AND
    // || = logical OR, | = bitwise OR
    if ( (a < b) && (a < c) ) {
        cout << "a is smallest" << endl;
    }
    if ( (b < a) && (b < c) ) {
        cout << "b is smallest" << endl;
    }
    if ( (c < a) && (c < b) ) {
        cout << "c is smallest" << endl;
    }
    
    // TODO: print all three in order

    return 0;
}

int main() {
    /*
A peak is local maximum, for example in the values [1, 4, 7, 5, 3, 4], 7 is the peak because 7 >= 4 and 7>=5.

start with array of ints (n>=0) and an int current_max (what is a good initiazlization value for cureent_max? (0, V[0]), etc.) )
given vector iterate through,
    compare each n with current_max
        if n > current_max
            current_max = n
        when done, current_max is global max
    */

    // Ref, C++ Language Companion for initializing an array
    const int SIZE = 6;
    int values [SIZE] = {1, 4, 7, 5, 3, 4};

    int current;
    
    // optional: take user input
    for (int i=0; i < SIZE; i++) {
        cout << "Value[" << i << "]: ";
        cin >> values[i];
    }
    cout << endl;
    
    int current_max = values[0]; // start with the first value

    cout << "V=";
    for (int i=0; i < SIZE; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    cout << "Now finding maximum n in V" << endl;
    for (int i=0; i < SIZE; i++) {
        current = values[i]; // for each n in V
        cout << current << endl;
        if (current > current_max) {
            current_max = current;
            cout << "\t" << "current_max now: " << current_max << endl;
        }
    }
    // done -- current_max is global maximum
    cout << "Largest value in V is: " << current_max << endl;

    return 0;
}