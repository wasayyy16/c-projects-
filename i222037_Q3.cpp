//Abdul Wasay
//22i-2037
//Ds-B
#include<iostream>
#include<cstring>
using namespace std;

void checkSubsequent(char *str1, char *str2, int s1, int s2, int i, int j) {
    // Base case: If we have reached the end of str2, it's a subsequent of str1.
    if (j == s2) {
        cout << "True";
        return;
    }

    // Base case: If we have reached the end of str1 but not str2, it's not a subsequent.
    if (i == s1) {
        cout << "False";
        return;
    }

    if (str1[i] == str2[j]) {
        checkSubsequent(str1, str2, s1, s2, i + 1, j + 1);
    } else {
        checkSubsequent(str1, str2, s1, s2, i + 1, 0);
    }
}

int main() {
    char str1[100];
    char str2[100];
    
    cout << "Enter the first string: ";
    cin.getline(str1, sizeof(str1));
    int s1 = strlen(str1); 
    
    cout << "Enter the second string: ";
    cin.getline(str2, sizeof(str2));
    int s2 = strlen(str2); 

    if (s2 > s1) {
        cout << "Invalid Input." << endl;
    } else {
        checkSubsequent(str1, str2, s1, s2, 0, 0);
    }

    return 0;
}


