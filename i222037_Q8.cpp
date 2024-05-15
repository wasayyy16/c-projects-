//Abdul Wasay
//22i-2037
//Ds-B


#include<iostream>
using namespace std;
void CheckEqualSumArrays(int** array1,int** array2,int** array3,int count);
void CheckDifferentArrays(int** array1,int** array2,int** array3, int count);
void CheckEqualArrays(int** array1,int** array2,int** array3,int count1,int count2,int count3);
void FindSameRows(int** array1,int** array2,int** array3,int count1,int count2);
void RotateArrays(int** array1,int** array2,int** array3);
int main(){
	const int r = 2;
    const int c = 2;
    //dynamically allocating storage and taking inputs 
    
	//array1 
	int** array1 = new int*[r]; 
    for (int i = 0; i < r; i++) {
        array1[i] = new int[c]; 
    }

    cout << "Input array 1 :" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> array1[i][j]; 
        }
    }
    //array2
     int** array2 = new int*[r]; 
    for (int i = 0; i < r; i++) {
        array2[i] = new int[c]; 
    }

    cout << "Input array 2 :" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> array2[i][j]; 
        }
    }
    //array3
     int** array3 = new int*[r]; 
    for (int i = 0; i < r; i++) {
        array3[i] = new int[c]; 
    }

    cout << "Input array 3 :" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> array3[i][j]; 
        }
    }
	int x,count=0,count1=0,count2=0,count3=0;
	cout<<"Enter 1 for checking sum, 2 for checking difference , 3 for checking equality, 4 for checking rows and 5 for rotating arrays."<<endl;
	cin>>x;
	if (x==1){
	CheckEqualSumArrays(array1,array2,array3,count);
	}	
	else if (x==2){
		CheckDifferentArrays(array1,array2,array3,count);
	}
	else if (x==3){
		CheckEqualArrays(array1,array2,array3,count1,count2,count3);
	}
	else if (x==4){
		 FindSameRows(array1,array2,array3,count1,count2);
	}
	else if (x==5){
		RotateArrays(array1,array2,array3);
	}
	else {
		cout<<"Invalid Input.";
	}
	
	//deallocating memory
	for (int i = 0; i < r; i++) {
        delete[] array1[i]; 
    }
    delete[] array1;
	for (int i = 0; i < r; i++) {
        delete[] array2[i]; 
    }
    delete[] array2;
	for (int i = 0; i < r; i++) {
        delete[] array3[i]; 
    }
    delete[] array3;
	return 0;
}
	//fun1
	
	void CheckEqualSumArrays(int** array1,int** array2,int** array3,int count){
		int *temp= new int;
	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
         *temp=(array1[i][j])+(array2[i][j]);
		 if (*temp=array3[i][j]){
		 	count++;
		 }   
        }
    }
    delete temp;
    if (count==4){
    	cout<<"Sum of first two array is equal to third."<<endl;
	}
	else {
		cout<<"Sum of first two array is not equal to third."<<endl;
	}
}
	//fun2
	void CheckDifferentArrays(int** array1, int** array2, int** array3, int count) {
    int* temp = new int; 

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            *temp = (array1[i][j]) - (array2[i][j]);
            if (*temp == array3[i][j]) { 
                count++;
            }
        }
    }

    delete temp; 

    if (count == 4) {
        cout << "Difference of the first two arrays is equal to the third." << endl;
    }
    else {
        cout << "Difference of the first two arrays is not equal to the third." << endl;
    }
}


	//fun3
	void CheckEqualArrays(int** array1,int** array2,int** array3,int count1,int count2,int count3){
	//for array 1 and 3
	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
        
		 if (array1[i][j]==array3[i][j]){
		 	count1++;
		 }   
        }
    }
    if (count1==4){
    	cout<<"Array 1 and 3 are equal."<<endl;
	}
	else {
		cout<<"Array 1 and 3 are not equal."<<endl;
	}
		//for array 1 and 2
		
	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
        
		 if (array1[i][j]==array2[i][j]){
		 	count2++;
		 }   
        }
    }
    if (count2==4){
    	cout<<"Array 1 and 2 are equal."<<endl;
	}
	else {
		cout<<"Array 1 and 2 are not equal."<<endl;
	}
		//for array 2 and 3
	
	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
        
		 if (array2[i][j]==array3[i][j]){
		 	count3++;
		 }   
        }
    }
    if (count3==4){
    	cout<<"Array 2 and 3 are equal."<<endl;
	}
	else {
		cout<<"Array 2 and 3 are not equal."<<endl;
	}
}
	
	

	//fun4
	void FindSameRows(int** array1,int** array2,int** array3,int count1,int count2){
	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
        //for row1
		 if (array1[0][j]==array2[0][j] && array1[0][j]==array3[0][j] && array3[0][j]==array2[0][j]){
		 	count1++;
		 }   
		 //for row 2
		 if (array1[1][j]==array2[1][j] && array1[1][j]==array3[1][j] && array3[1][j]==array2[1][j]){
		 	count2++;
		 } 
        }
    }
	if (count1==2){
		cout<<"Row 1 is common in all matrices."<<endl;
	}
	else if (count2==2){
		cout<<"Row 1 is common in all matrices."<<endl;
	}
	else {
		cout<<"Neither row is common."<<endl;
	}
}
	//fun5
	void RotateArrays(int** array1,int** array2,int** array3){
	//for array1
	cout<<"Original array 1 is : "<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout<< array1[i][j]<<" "; 
        }
        cout<<endl;
    }
	int temp1 = array1[0][0]; 
    array1[0][0] = array1[1][0]; 
    array1[1][0] = array1[1][1]; 
    array1[1][1] = array1[0][1]; 
    array1[0][1] = temp1; 
    cout<<"Inverted array 1 is : "<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout<< array1[i][j]<<" "; 
        }
        cout<<endl;
    }
    //for array2
    cout<<"Original array 2 is : "<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout<< array2[i][j]<<" "; 
        }
        cout<<endl;
    }
	int temp2 = array2[0][0]; 
    array2[0][0] = array2[1][0]; 
    array2[1][0] = array2[1][1]; 
    array2[1][1] = array2[0][1]; 
    array2[0][1] = temp2; 
    cout<<"Inverted array 2 is : "<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout<< array2[i][j]<<" "; 
        }
        cout<<endl;
    }
    
    
    //for array3
    cout<<"Original array 3 is : "<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout<< array3[i][j]<<" "; 
        }
        cout<<endl;
    }
	int temp3 = array3[0][0]; 
    array3[0][0] = array3[1][0]; 
    array3[1][0] = array3[1][1]; 
    array3[1][1] = array3[0][1]; 
    array3[0][1] = temp3; 
    cout<<"Inverted array 3 is : "<<endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout<< array3[i][j]<<" "; 
        }
        cout<<endl;
    }
}


