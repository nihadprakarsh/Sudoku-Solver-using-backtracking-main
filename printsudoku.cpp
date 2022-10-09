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
