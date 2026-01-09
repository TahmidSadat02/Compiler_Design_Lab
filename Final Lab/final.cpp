#include <iostream>
#include <string>
using namespace std;


int checkString(const string &input) {
    int state = 0;   

    
    for (char ch : input) {

        if (ch != 'a' && ch != 'b') {
            cout << "Invalid input! Only a and b allowed.\n";
            return 0;
        }

        if (state == 0) {           
            if (ch == 'a')
                state = 1;
            else
                state = 0;
        }
        else if (state == 1) {      
            if (ch == 'b')
                state = 2;
            else
                state = 1;
        }
        else if (state == 2) {      
            if (ch == 'b')
                state = 3;
            else
                state = 1;
        }
        else if (state == 3) {      
            if (ch == 'a')
                state = 1;
            else
                state = 0;
        }
    }

    if (state == 3)
        return 1;   
    else
        return 0;   
}

int main() {
    string input;

    cout << "Enter a string (only a or b): ";
    if (!getline(cin, input)) {
        cout << "No input received.\n";
        return 0;
    }

    if (checkString(input))
        cout << "String Accepted\n";
    else
        cout << "String Rejected\n";

    return 0;
}
