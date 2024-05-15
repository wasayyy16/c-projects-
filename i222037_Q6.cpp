//Abdul Wasay
//22i-2037
//Ds-B
#include<iostream>
using namespace std;

int main() {
    const int r = 3;
    const int c = 3;
    int* array[r][c]; 
    int sumeven=0,sumodd=0;
    
    cout << "Input array:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            array[i][j] = new int; 
            cin >> *(array[i][j]); 
        }
    }

    cout << "Input array is:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << *(array[i][j]) << " "; 
            if ((*array[i][j])%2==0){
            	sumeven+=(*array[i][j]);
			}
			if ((*array[i][j])%2==1){
            	sumodd+=(*array[i][j]);
			}
            delete array[i][j]; 
        }
        cout << endl;
    }
    cout<<"Sum of even numbers in the array is : "<<sumeven<<endl;
    cout<<"Sum of odd numbers in the array is : "<<sumodd<<endl;
    
    

    return 0;
}







