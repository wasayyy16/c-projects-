#include <iostream>
using namespace std;

void printPattern(int n, int i, int j, int value) {
    if (i >= n) {
        return;
    }

    if (j <= i) {
        cout << value << " ";
        printPattern(n, i, j + 1, 1);
    } else {
        cout << endl;
        printPattern(n, i + 1, 0, n - i - 1);
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for the pattern: ";
    cin >> n;
    cout << "Pattern:" << endl;
    printPattern(n, 0, 0, n);
    return 0;
}

