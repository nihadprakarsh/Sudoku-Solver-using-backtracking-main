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