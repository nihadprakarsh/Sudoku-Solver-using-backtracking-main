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