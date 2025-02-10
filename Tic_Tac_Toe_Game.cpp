#include<bits/stdc++.h>
using namespace std;

// here using ANSI escape codes to color text output which is supported in most of the terminals
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BROWN   "\033[38;5;94m"


int currentplayer;
int currentmarker;


// To show or print the Board 
void drawboard(char board[3][3])               
{
   cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
   cout<<"---|---|---"<<endl;
   cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
   cout<<"---|---|---"<<endl;
   cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}


/* To check whether slot is already occupied or not and if not occupied 
 then place the current marker*/
bool placeMarker(char board[3][3],int slot)
{
    int row=(slot-1)/3;
    int col=(slot-1)%3;

    if(board[row][col]!='X' && board[row][col]!='O')
    {
      board[row][col]=currentmarker;
      return true;
    }
    else
    { return false; }
}

// To check after every move whether there is a winner or not
int checkWinner(char board[3][3])
{
   // checking rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && (board[i][0] == 'X' || board[i][0] == 'O'))
        { return currentplayer; }
    }

    // checking for column
    for(int i=0;i<3;i++)
    {
      if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && (board[0][i] == 'X' || board[0][i] == 'O'))
        { return currentplayer; }  
    }

    // checking for diagonal
      if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && (board[0][0] == 'X' || board[0][0] == 'O')) 
       {
        return currentplayer;
       }
       if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && (board[0][2] == 'X' || board[0][2] == 'O'))
       {
        return currentplayer;
       }
       return 0;
}

void swap_player_and_marker()
{

  // changing marker with respect for player 1 and 2
  if(currentmarker == 'X')
  {
    currentmarker = 'O';
  }
  else
  {
    currentmarker = 'X';
  }


  // if currentplayer is 1 then next chance is for player 2 
  // OR
  // if currentplayer is 2 then next chance is for player 1 
  if(currentplayer == 1)
  {
    currentplayer = 2;
  }
  else
  {
    currentplayer = 1;
  }


}

void playTicTacToe()
{

  char board[3][3]={{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'}
                   };

   cout<<"Player 1 choose your marker: X or O ";
   char markerp1;
   cin>>markerp1;

   currentplayer=1;
   currentmarker=markerp1;
   drawboard(board);
   int playerwon;
   for(int i=0;i<9;i++)
   {
      cout<<"its player "<<currentplayer<<"'s turn Enter your slot: ";
      int slot;
      cin>>slot;
      if(slot<1 || slot>9)
      {
        cout << RED << "Invalid slot. Try again!" << RESET << endl;
        i--;
        continue;
      }

     // To check whether slot is already occupied or not
      if(!placeMarker(board,slot))
      {
        cout << RED << "Slot occupied! Try again." << RESET << endl;
        i--;
        continue;
      }
     //  after every move we have to show drawboard 
      drawboard(board);


     // To check after every move whether there is a winner or not
     playerwon=checkWinner(board);

     // check player 1 won or not 
     if(playerwon == 1) 
     {
        cout << GREEN << "Player 1 wins!" << RESET << endl;
        break;
     }
     // check player 1 won or not
     if(playerwon == 2) 
     {
      cout << GREEN << "Player 2 wins!" << RESET << endl;
        break;
     }

     // if anyone is not won then we have to continue game by swapping both the player
     swap_player_and_marker();

     
           
    }

    // To check if the game is tied or not
    if(playerwon==0)
    {
       cout<< BROWN <<"its a tie"<< RESET ;
    } 

}


int main()
{
    playTicTacToe();

    string play_again;
    cout<<"\nDo you want to play another game? (yes/no): ";
    cin>>play_again;
    while(play_again=="yes" || play_again=="Yes" || play_again=="YES") 
    {
      playTicTacToe(); 
      cout<<"\nDo you want to play Another Game!:";
      cin>>play_again;
    }
    
   return 0;
}
