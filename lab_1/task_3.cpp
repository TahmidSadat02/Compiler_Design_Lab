#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    
    cout << "Enter input: ";
    getline(cin, input); 
    
    if (input.length() >= 2 && input[0] == '/' && input[1] == '/') {
        cout << "This is a single-line comment" << endl;
        return 0;
    }

    if (input.length() >= 4) {

        if (input[0] == '/' && input[1] == '*') {

            if (input[input.length()-2] == '*' && input[input.length()-1] == '/') {
                cout << "This is a multi-line comment" << endl;
                return 0;
            } else {
                cout << "This is the start of a multi-line comment" << endl;
                return 0;
            }
        }
    }
    
    if (input.length() >= 2) {
        if (input[input.length()-2] == '*' && input[input.length()-1] == '/') {
            cout << "This is the end of a multi-line comment" << endl;
            return 0;
        }
    }
    
    cout << "This is not a comment" << endl;
    
    return 0;
}
