#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    int arr[n];
    cout << "Enter elements:\n";

    cin >> arr[0];
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        cin >> arr[i];

        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;

    return 0;
}

