#include <iostream>
#include <string>
using namespace std;

bool isValidIdentifier(string str) {
    
    if (str.empty()) {
        return false;
    }
    
    if (!((str[0] >= 'A' && str[0] <= 'Z') || 
          (str[0] >= 'a' && str[0] <= 'z') || 
          (str[0] == '_'))) {
        return false;
    }
    
    for (int i = 1; i < str.length(); i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || 
              (str[i] >= 'a' && str[i] <= 'z') || 
              (str[i] >= '0' && str[i] <= '9') || 
              (str[i] == '_'))) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string input;
    
    cout << "Enter a string to check identifier: ";
    cin >> input;
    
    if (isValidIdentifier(input))
        cout << input << " is a VALID identifier.\n";
    else
        cout << input << " is NOT a valid identifier.\n";
    
    return 0;
}
