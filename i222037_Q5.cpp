//Abdul Wasay
//22i-2037
//Ds-B
#include<iostream>
using namespace std;

void inversionscount(int** array, int r, int c, int& ic, int i, int j) {
    if (i < r && j < c) {
        if (i < j && array[i][j] > array[j][i]) {
            ic++;
        }
        inversionscount(array, r, c, ic, i, j + 1);
    } 
	else if (i < r - 1) {
        inversionscount(array, r, c, ic, i + 1, i + 2);
    }
}

int main() {
    const int r = 3;
    const int c = 3;
    int** array = new int*[r]; 
    int ic = 0;

    for (int i = 0; i < r; i++) {
        array[i] = new int[c]; 
    }

    cout << "Input array:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> array[i][j]; 
        }
    }

    inversionscount(array, r, c, ic, 0, 1);
    cout << "Inversion count is : " << ic << endl;

    for (int i = 0; i < r; i++) {
        delete[] array[i]; 
    }
    delete[] array;

    return 0;
}

