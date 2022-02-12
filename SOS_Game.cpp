#include <iostream>
#include <string>


using namespace std;

//This is the matrix that would be use in making the board for the game
char matrix[8][8] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',};


char player = 'S';

int n; // This is the variable to count the number of rounds in the game. 
       // Making it possible to know if the game is finished.

int sPoints; //Points of the S player.
int oPoints; //Points of the O player.



//This function initiates the boardgame made using the 8x8 matrix array.
void Draw()
{
    system("cls");
    cout << "SOS GAME !\n" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void xPoints() //Function serves to add points to the S player.
{
   sPoints ++;
}


void lPoints() //Function serves to add points to the O player.
{
   oPoints ++;
}


void showPoints() //This function is to output the total points for each player.
{
  cout<<"S Points are = "<<sPoints<<"     "<<"O points are = "<<oPoints<<endl;
}


void Input() //This function updates the display board that is use 
{            //So that players can see their moves realtime.
    int a; 
    int b;
    cout << "\nIt's " << player << " turn. " << "Input X and Y axis of choice: ";
    cin >> a;
    cin >> b;


    if (matrix[a][b] == '-')
    {
      matrix[a][b] = player;
    }
    else
    {
      cout << "Field is already in use try again!" << endl;
      Input();
    }
    
}


void TogglePlayer() //This toggles an exchange of control for each player every round.
{
    if (player == 'S')
        player = 'O';
    else
        player = 'S';
}


char Win() //Here is the function that tallies the score after the game is over.
{
    //first player
    for(int i = 0; i < 8; i++)
    {
      for (int j =0; j < 6; j++)
        if (matrix[i][j] == 'S' && matrix[i][j+1] == 'O' && matrix[i][j+2] == 'S')
          xPoints();
        else if (matrix[j][i] == 'S' && matrix[j+1][i] == 'O' && matrix[j+2][i] == 'S')
          xPoints();
    
    }
    for(int i = 0; i < 5; i++)
    {
      if (matrix[i][i] == 'S' && matrix[i+1][i+1] == 'O' && matrix[i+2][i+2] == 'S')
          xPoints();
    
    }
    


    //second player
    for(int i = 0; i < 8; i++)
    {
      for (int j =0; j < 6; j++)
        if (matrix[i][j] == 'O' && matrix[i][j+1] == 'S' && matrix[i][j+2] == 'O')
          lPoints();
        else if (matrix[j][i] == 'O' && matrix[j+1][i] == 'S' && matrix[j+2][i] == 'O')
          lPoints();
    
    }
    for(int i = 0; i < 5; i++)
    {
      if (matrix[i][i] == 'O' && matrix[i+1][i+1] == 'S' && matrix[i+2][i+2] == 'O')
          lPoints();
    
    }

    return 0;
}


void Winner() //This is basically the function that announces the winner.
{
    if(sPoints > oPoints)
    {
      cout<<"Overall Point! S:"<<sPoints<<" O:"<<oPoints<<endl;
      cout<<"S wins!";
    }
    else if(sPoints < oPoints)
    {
      cout<<"Overall Point! S:"<<sPoints<<" O:"<<oPoints<<endl;
      cout<<"O wins!";
    }
    else
    {
      cout<<"Overall Point! S:"<<sPoints<<" O:"<<oPoints<<endl;
      cout<<"It's a Draw!";
    }
}

int main()
{
    sPoints = 0;
    oPoints = 0;
    n = 0;
    Draw();
    while (n<64) //64 rounds is enough to fully occupy the whole arena of the game.
    {
        n++;
        Input();
        Draw();
        TogglePlayer();
        if (n == 64) //This tells the program that the board is fully utilize and the game ends.
        {
           Win();
           Winner();
        }
    }
    system("pause");
    return 0;
}