#include <iostream>
#include <string>
using namespace std;

bool isNumericConstant(string input) {
    
    if (input.empty()) {
        return false;
    }  
    for (int i = 0; i < input.length(); i++) {
        
        if (!isdigit(input[i])) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string input;
    
    cout << "Enter input: ";
    cin >> input;
    
    if (isNumericConstant(input)) {
        cout << "\"" << input << "\" is a numeric constant" << endl;
    } else {
        cout << "\"" << input << "\" is not numeric" << endl;
    }
    
    return 0;
}
