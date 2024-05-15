//Abdul Wasay
//22i-2037
//Ds-B
#include <iostream>
#include <cstring>
using namespace std;

void ChangeLocation(char* array, int b1, int b2) {
    //base case
	if (b1 >= b2) {
        return;
    }
    //recursive case
    else {
	if (b1==2 && b2==6){
    char temp = array[b1];
    array[b1] = array[b2];
    array[b2] = temp;
}
    ChangeLocation(array, b1 + 1, b2 - 1);
}
}

int main() {
    char array[] = "PAKISTAN";
    int b1 =2;
    int b2 = 6;

    cout << "Original String: " << array << endl;

    ChangeLocation(array, b1, b2);

    cout << "Modified String: " << array << endl;

    return 0;
}
