#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;


bool isValidIdentifier(const string& word) {
    
    if (word.empty()) {
        return false;
    }
    
    
    if (!isalpha(word[0]) && word[0] != '_') {
        return false;
    }
    
    
    for (size_t i = 1; i < word.length(); i++) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return false;
        }
    }
    
    return true;
}

int main() {
    ifstream inputFile("input.txt");
    
    
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }
    
    string word;
    
    
    while (inputFile >> word) {
        if (isValidIdentifier(word)) {
            cout << word << " is a valid identifier." << endl;
        } else {
            cout << word << " is NOT a valid identifier." << endl;
        }
    }
    
    
    inputFile.close();
    
    return 0;
}
