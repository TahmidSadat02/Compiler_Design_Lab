#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, lastName, fullName;

    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    fullName = firstName + " " + lastName;

    cout << "Full Name = " << fullName << endl;

    return 0;
}
