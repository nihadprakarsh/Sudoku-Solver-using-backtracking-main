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