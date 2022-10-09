#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<vector<int>> v;
bool solved=false;

void about_sudoku(){
    cout<<"The objective in sudoku is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 subgrids that compose the grid (also called 'boxes', 'blocks', or 'regions') contain all of the digits from 1 to 9."<<endl<<"The puzzle setter provides a partially completed grid (one which you must have right now), which for a well-posed puzzle has a single solution."<<endl;

}

void printsudoku(){
    cout<<endl<<" ___ ___ ___ ___ ___ ___ ___ ___ ___"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(v[i][j]!=0){
                cout<<"| "<<v[i][j]<<" ";
            }
            else{
                cout<<"|   ";
            }
            
        }
        cout<<"|"<<endl<<" ___ ___ ___ ___ ___ ___ ___ ___ ___"<<endl;
    }
    cout<<endl;
}


bool check(int i, int j, int val){ //checks whether val is a valid value for cell[i][j]
    //check on corresponding row and column
    for(int k=0;k<9;k++){
        if(v[i][k]==val || v[k][j]==val) return false;
    }
    //checking the 3x3 grid
    //for i=0,1,2 the starting row will be 0; for 3,4,5 starting row=3 and so on
    //similar for column
    int toprow= (i/3)*3; int leftmostcol=(j/3)*3;
    for(int row=toprow; row<toprow+3; row++){
        for(int col=leftmostcol; col<leftmostcol+3; col++){
            if(v[row][col]==val) return false;
        }
    }
    return true; //no occurrence of val found in corresponding row, column, 3x3 grid
}
void sudoku(int i, int j){
    if(i==9){
        //we have obtained a valid ans-- return
        solved=true;
        return;
    }
    else if(v[i][j]==0){ //we need to assign a value
        for(int val=1;val<=9;val++){
            if (check(i,j,val)){
                v[i][j]=val;
                if(j==8) sudoku(i+1,0);
                else sudoku(i,j+1);
                if(!solved) v[i][j]=0; //backtracking
            }
        }

    }
    else{ //this cell is already filled, so we proceed to the next one
        if(j==8) sudoku(i+1,0);
        else sudoku(i,j+1);

    }
}
void solve(){
    v.assign(9,vector<int>(9,0));
    cout<<"Input your sudoku in the following format:"<<endl;
    cout<<"Enter the values column-wise for ever row. First enter the column-wise elements in the first row and proceed to the other rows in similar fashion"<<endl;
    cout<<"Enter the given values at respective positions and denote empty cells with a '.' character (without the quotes) or with a 0"<<endl;
    cout<<"DO NOT DENOTE EMPTY CELLS WITH A SPACE"<<endl;
    cout<<endl<<"Input your sudoku:"<<endl;
    for(int i=0;i<9;i++){
        string s; cin>>s;
        for(int j=0;j<9;j++){
            if (s[j]!='.') v[i][j]=s[j]-'0';
        }
    }
    cout<<"Your sudoku looks like this:"<<endl;
    printsudoku();
    cout<<endl<<"Enter Y to proceed, and any other key to input again"<<endl;
    char ch; cin>>ch;
    if(ch=='Y' || ch=='y'){
        solved=false;
        sudoku(0,0);
        cout<<"Solved sudoku:"<<endl;
        printsudoku();
    }
    else{
        solve();
    }
    
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    // cin.tie(NULL);cout.tie(NULL);
    cout<<"*********WELCOME TO THE SUDOKU SOLVER*********"<<endl;
    while(true){
        cout<<"Enter 1 to learn about sudoku"<<endl<<"Enter 2 to solve your sudoku!"<<endl<<"Enter 3 to exit"<<endl;
        cout<<endl<<"Enter your choice:"<<endl;
        int choice; cin>>choice;
        if(choice==3){
            cout<<"Thanks for using the sudoku solver!"<<endl;
            break;
        }
        if(choice==1){
            about_sudoku();
            cout<<endl<<"Press any key to continue"<<endl;
            string temp; cin>>temp;
            solve();
        }
        else solve();
    }
}