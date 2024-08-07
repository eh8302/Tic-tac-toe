#include<iostream>
using namespace std;

char current_marker;
int current_player;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawboard(){
    cout<<" "<<board[0][0]<<" | " << board[0][1] << " | " << board[0][2] <<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<board[1][0]<<" | " << board[1][1] << " | " << board[1][2] <<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<board[2][0]<<" | " << board[2][1] << " | " << board[2][2] <<endl;
}

bool placemarker(int slot){
    int row=(slot-1)/3;
    int col=(slot-1)%3;

    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = current_marker;
        return true;
    }else{
        return false;
    }
}

int winner(){
    //checking for row
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return current_player;
        }
    }
    //checking for col
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return current_player;
        }
    }
    //Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return current_player;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return current_player;
    }
    return 0;
}
void swap_playerANDmarker(){
    if(current_marker == 'X') current_marker ='O';
    else current_marker = 'X';

    if(current_player == 1)current_player = 2;
    else current_player = 1;
}


void game(){
    cout<<"Player 1 , Choose your marker (X or O):";
    char P1; 
    cin>>P1;

    current_player=1;
    current_marker=P1;

    drawboard();

    int Player_won;

    for(int i=0;i<9;i++){
        cout<<"It's player "<<current_player<<"'s turn. Enter Your slot : ";
        int slot;
        cin>>slot;

        if(slot>9 || slot<1){
            cout<<"Entered slot is invalid! Please enter valid slot!" <<endl;
            i--;
            continue;
        }
        if(!placemarker(slot)){
            cout<<"Entered slot is already marked! Please enter another slot!"<<endl;
            i--;
            continue;
        }
        drawboard();

        Player_won = winner();

        if(Player_won == 1){
            cout<<"Player 1 won! Congratulation!";
            break;
        }
        if(Player_won == 2){
            cout<<"Player 2 won! Congratulation!";
            break;
        }
        swap_playerANDmarker();
    }
    if(Player_won == 0){
        cout << "That's a draw!"<<endl;
    }
}

int main(){
    game();
    return 0;
}