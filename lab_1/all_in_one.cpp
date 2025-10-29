#include <iostream>
#include <string>
using namespace std;


void identifierChecker();
void commentDetector();
void minMaxCalculator();
void nameExtractor();
void averageCalculator();
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore();
        
        
        switch(choice) {
            case 1:
                identifierChecker();
                break;
            case 2:
                commentDetector();
                break;
            case 3:
                minMaxCalculator();
                break;
            case 4:
                nameExtractor();
                break;
            case 5:
                averageCalculator();
                break;
            case 6:
                cout << "Thank you for using the program! Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select 1-6.\n";
        }
        
        
    } while(choice != 6);
    
    return 0;
}

void displayMenu() {
    cout << "  COMPILER DESIGN LAB - MENU      \n";
    cout << "  1. Identifier Checker\n";
    cout << "  2. Comment Detector\n";
    cout << "  3. Min/Max Calculator (Array)\n";
    cout << "  4. First & Last Name Extractor\n";
    cout << "  5. Average Calculator\n";
    cout << "  6. Exit\n";
    cout << "────────────────────────────────────────\n";
}


void identifierChecker() {
    cout << "=== IDENTIFIER CHECKER ===\n\n";
    string input;
    
    cout << "Enter a string to check: ";
    getline(cin, input);
    
    if (input.empty()) {
        cout << " NOT a valid identifier (empty string)\n";
        return;
    }
    

    if (!((input[0] >= 'A' && input[0] <= 'Z') || 
          (input[0] >= 'a' && input[0] <= 'z') || 
          (input[0] == '_'))) {
        cout << " \"" << input << "\" is NOT a valid identifier.\n";
        cout << "   Reason: First character must be a letter or underscore.\n";
        return;
    }
    

    for (int i = 1; i < input.length(); i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') || 
              (input[i] >= 'a' && input[i] <= 'z') || 
              (input[i] >= '0' && input[i] <= '9') || 
              (input[i] == '_'))) {
            cout << " \"" << input << "\" is NOT a valid identifier.\n";
            cout << "   Reason: Invalid character '" << input[i] << "' at position " << (i+1) << ".\n";
            return;
        }
    }
    
    cout << " \"" << input << "\" is a VALID identifier.\n";
}


void commentDetector() {
    cout << "=== COMMENT DETECTOR ===\n\n";
    string input;
    
    cout << "Enter a line to check: ";
    getline(cin, input);
    

    int start = 0;
    while (start < input.length() && (input[start] == ' ' || input[start] == '\t')) {
        start++;
    }
    

    if (start + 1 < input.length() && input[start] == '/' && input[start + 1] == '/') {
        cout << " This is a SINGLE-LINE COMMENT (//).\n";
        return;
    }
    

    if (start + 1 < input.length() && input[start] == '/' && input[start + 1] == '*') {
        int end = input.length() - 1;
        while (end >= 0 && (input[end] == ' ' || input[end] == '\t')) {
            end--;
        }
        
        if (end >= 1 && input[end] == '/' && input[end - 1] == '*') {
            cout << " This is a MULTI-LINE COMMENT (/* */).\n";
            return;
        }
    }
    
    cout << " This is NOT a comment.\n";
}
void minMaxCalculator() {
    cout << "=== MIN/MAX CALCULATOR ===\n\n";
    int n;
    
    cout << "Enter array size: ";
    cin >> n;
    
    if (n <= 0) {
        cout << " Array size must be greater than 0!\n";
        return;
    }
    
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "  Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    cout << "\n Results:\n";
    cout << "   Minimum = " << min << "\n";
    cout << "   Maximum = " << max << "\n";
}

void nameExtractor() {
    cout << "=== FIRST & LAST NAME EXTRACTOR ===\n\n";
    string fullName;
    
    cout << "Enter your full name: ";
    getline(cin, fullName);
    
    int spacePos = -1;
    for (int i = 0; i < fullName.length(); i++) {
        if (fullName[i] == ' ') {
            spacePos = i;
            break;
        }
    }
    
    if (spacePos == -1) {
        cout << " Please enter both first and last name.\n";
        return;
    }
    
    string firstName = fullName.substr(0, spacePos);
    string lastName = fullName.substr(spacePos + 1);
    
    cout << "\n Extracted Names:\n";
    cout << "   First Name: " << firstName << "\n";
    cout << "   Last Name: " << lastName << "\n";
}


void averageCalculator() {
    cout << "=== AVERAGE CALCULATOR ===\n\n";
    int n;
    
    cout << "Enter number of values: ";
    cin >> n;
    
    if (n <= 0) {
        cout << " Number of values must be greater than 0!\n";
        return;
    }
    
    double sum = 0;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        double value;
        cout << "  Value " << (i + 1) << ": ";
        cin >> value;
        sum += value;
    }
    
    double average = sum / n;
    
    cout << "\n Results:\n";
    cout << "   Sum = " << sum << "\n";
    cout << "   Average = " << average << "\n";
}
