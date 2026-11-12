/*
* more credit card
* Korbin Landrum
*/

#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
bool isNumeric(string s);
bool isCorrectLength(string s);
bool isCardValid(int digits[], int size);

int main() {
    const int SIZE = 16;
    int digits[SIZE];
    string input;

    while (true) {
        cout << "Enter 16-digit credit card # or Q to quit: ";
        cin >> input;

        if (input == "Q" || input == "q") {
            break;
        }

        if (!isNumeric(input)) {
            cout << "Error - card number must contain only digits." << endl;
            continue;
        }

        if (!isCorrectLength(input)) {
            cout << "Error - card number must contain 16 digits." << endl;
            continue;
        }

        // Convert each character digit into the integer array
        for (int i = 0; i < SIZE; i++) {
            digits[i] = input[i] - '0';
        }

        if (isCardValid(digits, SIZE)) {
            cout << "Card is valid." << endl;
        }
        else {
            cout << "Card is not valid." << endl;
        }
    }

    return 0;
}

// checks for onl 0 through 9
bool isNumeric(string s) {
    if (s.empty()) {
        return false;
    }

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

// check for 16 characters
bool isCorrectLength(string s) {
    return s.length() == 16;
}

bool isCardValid(int digits[], int size) {
    int sumUnchanged = 0;
    int sumDoubled = 0;

    // Traverse from right to left
    for (int i = size - 1; i >= 0; i--) {
        int positionFromRight = (size - 1) - i;

        if (positionFromRight % 2 == 0) {
            // Every other digit starting from the rightmost
            sumUnchanged += digits[i];
        }
        else {
            // Remaining digits: double and sum their individual digits
            int doubled = digits[i] * 2;
            sumDoubled += (doubled / 10) + (doubled % 10);
        }
    }

    int totalSum = sumUnchanged + sumDoubled;
    return (totalSum % 10 == 0);
}