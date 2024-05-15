#include<iostream>
#include<windows.h>
using namespace std;
void possible();
void start();
void ynm(char grid[][8]);
void yournextmove(char grid[][8]);
void multiplayer(char grid[][8]);
void loading(){
	system("cls");
	system("color 4F");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t Loading."<<endl;
    char w = 219;
    cout<<"\t\t\t\t\t";
    for(int i=0;i<23;i++){
    	cout<<w;
    	Sleep(100);
}
cout<<endl<<endl<<endl<<endl;
cout<<"\t\t\t\t\t     ARE YOU READY?"<<endl;
Sleep(3000);
system("cls");
}
int main(){
start();
	return 0;
}
void start(){
	//loading();
		const int bs=8;
	int x;
	cout<<"R is Rock."<<endl;
	cout<<"N is Knight."<<endl;
	cout<<"B is Bishop."<<endl;
	cout<<"Q is Queen."<<endl;
	cout<<"K is King."<<endl;
	 // Creating the chess board
  char grid[bs][bs] = {
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
  };

  // Displaying the chess board
  cout<<"Chess Board is : "<<endl;
  for (int row = 0; row < bs; row++) {
    for (int col = 0; col < bs; col++) {
      cout << grid[row][col] << "\t";
    }
    cout << endl;
  }
  int choice;
  cout<<"Enter 1 for Free mode, 2 for seeing possible moves at any set of points ,3 for Save the King : ";
  cin>>choice;
  if (choice==1){
  	yournextmove(grid);
  }
  else if (choice==2){
  	possible();
  }
  else if (choice==3){
  	multiplayer(grid);
  }
  else {
  	cout<<"Invalid Input!"<<endl;
  }

	
}
void ynm(char grid[][8]) {
    int x, a, b, r, c, u, v, p, q, count = 0;
    cout << "Enter 1 for king, 2 for queen, 3 for bishop, 4 for rook, and 5 for knight: ";
    cin >> x;
    cout << "Enter the position of the character you want to move:" << endl;
    cin >> p >> q;
    u = p - 1;
    v = q - 1;
    cout << "Enter the row and column of your desired position:" << endl;
    cin >> a >> b;
    r = a - 1;
    c = b - 1;
    char temp;

    if (x == 1) {
        if ((abs(u - r) == 1 && abs(v - c) == 0) || (abs(u - r) == 0 && abs(v - c) == 1) || (abs(u - r) == 1 && abs(v - c) == 1)) {
            temp = grid[u][v];
            grid[u][v] = grid[r][c];
            grid[r][c] = temp;
        } else {
            count++;
        }
    } else if (x == 3) {
        if (abs(u - r) == abs(v - c)) {
            temp = grid[u][v];
            grid[u][v] = grid[r][c];
            grid[r][c] = temp;
        } else {
            count++;
        }
    } else if (x == 4) {
        if ((u == r && v != c) || (u != r && v == c)) {
            temp = grid[u][v];
            grid[u][v] = grid[r][c];
            grid[r][c] = temp;
        } else {
            count++;
        }
    } else if (x == 2) {
        if ((u == r && v != c) || (u != r && v == c) || abs(u - r) == abs(v - c)) {
            temp = grid[u][v];
            grid[u][v] = grid[r][c];
            grid[r][c] = temp;
        } else {
            count++;
        }
    } else if (x == 5) {
        if ((abs(u - r) == 1 && abs(v - c) == 2) || (abs(u - r) == 2 && abs(v - c) == 1)) {
            temp = grid[u][v];
            grid[u][v] = grid[r][c];
            grid[r][c] = temp;
        } else {
            count++;
        }
    }

    if (count > 0) {
        cout << "Invalid Input!" << endl;
    }

    // Displaying the chess board
    cout << "Chess Board is: " << endl;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            cout << grid[row][col] << "\t";
        }
        cout << endl;
    }
}
 void multiplayer(char grid[][8]){
  	int n=0,cm=0;
  	int a,b,r,c;
	while (n<100){
		cout<<"Player 1 turn."<<endl;
		ynm(grid);
		cout<<"Player 2 turn."<<endl;
		ynm(grid);
		cout << "Enter the row and column of your desired position:" << endl;
    cin >> a >> b;
    r = a - 1;
    c = b - 1;
	 	for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
			
				//for queen
				if (grid[i][j] == 'K' && (grid[i+2][j] == 'q' || grid[i-2][j] == 'q' ||
					grid[i][j+2] == 'q' || grid[i][j-2] == 'q')){
					cm++;
					n = 111;
					break;
				}
				if (grid[i][j] == 'k' && (grid[i+2][j] == 'Q' || grid[i-2][j] == 'Q' ||
					grid[i][j+2] == 'Q' || grid[i][j-2] == 'Q')){
					cm++;
					n = 111;
					break;
				}
				
				//for knight
				if (grid[i][j] == 'K' && ((grid[i-2][j+1] == 'n' || grid[i+2][j-1] == 'n') ||
					(grid[i-2][j-1] == 'n' || grid[i+2][j+1] == 'n') ||
					(grid[i-1][j+2] == 'n' || grid[i+1][j-2] == 'n') || 
					(grid[i-1][j-2] == 'n' || grid[i+1][j+2] == 'n'))){
					cm++;
					n = 111;
					break;
				}
				if (grid[i][j] == 'k' && ((grid[i-2][j+1] == 'N' || grid[i+2][j-1] == 'N') ||
					(grid[i-2][j-1] == 'N' || grid[i+2][j+1] == 'N') ||
					(grid[i-1][j+2] == 'N' || grid[i+1][j-2] == 'N') || 
					(grid[i-1][j-2] == 'N' || grid[i+1][j+2] == 'N'))){
					cm++;
					n = 111;
					break;
				}
				
				//for rook
				if (grid[i][j] == 'K' && ((grid[i-2][j] == 'r' || grid[i+2][j] == 'r') || 
					(grid[i][j-2] == 'r' || grid[i][j+2] == 'r'))){
					cm++;
					n = 111;
					break;
				}
				if (grid[i][j] == 'k' && ((grid[i-2][j] == 'R' || grid[i+2][j] == 'R') || 
					(grid[i][j-2] == 'R' || grid[i][j+2] == 'R'))){
    cm++;
    n = 111;
    break;
}

// for bishop
if (grid[i][j] == 'K' && (abs(i - r) == 2 && abs(j - c) == 2)) {
    cm++;
    n = 111;
    break;
}
if (grid[i][j] == 'k' && (abs(i - r) == 2 && abs(j - c) == 2)) {
    cm++;
    n = 111;
    break;
}

}
}

if (n=111){
    cout<<"Check Mate!"<<endl;
    cout<<"The King is no more the king!"<<endl;
    break;
}
} 
}

  	void yournextmove(char (*grid)[8]) {
    int f = 2;
    while (f != 0) {
        cout << "Enter 0 to exit at any time and any other number to continue." << endl;
        cin >> f;
        ynm(grid);
    }
}


void possible(){
	int x,u,v,p,q;
	char pos[8][8] = {
      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
      {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
      {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
      {'.', ' ', '.', ' ', '.', ' ', '.', ' '}
  };
	cout<<"Enter 1 for king,2 for queen,3 for bishop,4 for rock and 5 for knight : ";
  cin>>x;
  cout<<"Enter position of the Character you want to check possible moves of. 'P' represents possible moves near spaces."<<endl;
  cin>>p>>q;
  u=p-1;
  v=q-1;
	if (x==3){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				for (int k=1;k<4;k++){
				if ((u-k>0 && v-k>0) && (u+k<7 && v+k<7)){
					pos[u][v]='B';
					pos[u-k][v-k]='P';
					pos[u+k][v+k]='P';
					pos[u-k][v+k]='P';
					pos[u+k][v-k]='P';
				}
				
				}
			}
		}
		// Displaying the chess board
  cout<<"Chess Board is : "<<endl;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      cout << pos[row][col] << "\t";
    }
    cout << endl;
  }
	}
	else if (x==4){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				for (int k=1;k<4;k++){
				if ((u-k>0 && v-k>0) && (u+k<7 && v+k<7)){
					pos[u][v]='R';
					pos[u][v-k]='P';
					pos[u][v+k]='P';
					pos[u-k][v]='P';
					pos[u+k][v]='P';
				}
				
				}
			}
		}
		// Displaying the chess board
  cout<<"Chess Board is : "<<endl;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      cout << pos[row][col] << "\t";
    }
    cout << endl;
  }
	}
	else if (x==5){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
					pos[u][v]='N';
					pos[u-2][v-1]='P';
					pos[u-2][v+1]='P';
					pos[u+2][v+1]='P';
					pos[u+2][v-1]='P';
					pos[u-1][v-2]='P';
					pos[u-1][v+2]='P';
					pos[u+1][v+2]='P';
					pos[u+1][v-2]='P';
				
				
				}
			}
		
		// Displaying the chess board
  cout<<"Chess Board is : "<<endl;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      cout << pos[row][col] << "\t";
    }
    cout << endl;
  }
}
	
	else if (x==1){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
			for (int k=1;k<4;k++){
				if ((u-1>0 && v-1>0) && (u+1<7 && v+1<7)){
					pos[u][v]='K';
					pos[u-1][v-1]='P';
					pos[u+1][v+1]='P';
					pos[u-1][v+1]='P';
					pos[u+1][v-1]='P';
				    pos[u-1][v]-='P';
					pos[u][v-1]='P';
					pos[u][v+1]='P';
					pos[u+1][v]='P';
				}
				
				}
			}
		}
		// Displaying the chess board
  cout<<"Chess Board is : "<<endl;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      cout << pos[row][col] << "\t";
    }
    cout << endl;
  }
	}
	else if (x==2){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				for (int k=1;k<4;k++){
				if ((u-k>0 && v-k>0) && (u+k<7 && v+k<7)){
					pos[u][v]='Q';
					pos[u-k][v-k]='P';
					pos[u+k][v+k]='P';
					pos[u-k][v+k]='P';
					pos[u+k][v-k]='P';
					pos[u][v-k]='P';
					pos[u][v+k]='P';
					pos[u-k][v]='P';
					pos[u+k][v]='P';
					
					pos[u-1][v-1]='P';
					pos[u+1][v+1]='P';
					pos[u-1][v+1]='P';
					pos[u+1][v-1]='P';
				    pos[u-1][v]-='P';
					pos[u][v-1]='P';
					pos[u][v+1]='P';
					pos[u+1][v]='P';
				}
				
				
				}
			}
		}
		// Displaying the chess board
  cout<<"Chess Board is : "<<endl;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      cout << pos[row][col] << "\t";
    }
    cout << endl;
  }
	}
	else {
		cout<<"Invalid Input!"<<endl;
	}
}

		
//ynm(grid);
  	
  
  
  

