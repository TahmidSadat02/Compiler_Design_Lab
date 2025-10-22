#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    cout << "Operators found:" << endl;

    for (char c : input) {
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=') {
            cout << "Operator: " << c << endl;
        }
    }

    return 0;
}
